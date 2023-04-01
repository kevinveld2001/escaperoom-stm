#include "buttons.h"

u_int8_t buttonsDown = B00000000;
u_int8_t newButtonsDown = B00000000;
unsigned long lastButtonScan = millis();
bool triggerEvent = true;

void buttonScanLoop() {
    
    newButtonsDown = tm.readButtons();
    
    if (buttonsDown == newButtonsDown) {
        lastButtonScan = millis();
    }

    if (millis() - lastButtonScan > 100) {
        lastButtonScan = millis();

        //only trigger event on button down 
        if (newButtonsDown > buttonsDown) triggerEvent = true;
        
        if (newButtonsDown != buttonsDown) {
            buttonsDown = newButtonsDown;
        }
    }
}

bool areButtonsPressed(uint8_t buttons) {
    return (buttonsDown & buttons) == buttons;
}

bool areButtonsPressedEvent(uint8_t buttons) {
    if (triggerEvent && areButtonsPressed(buttons)) {
        triggerEvent = false;
        return true;
    }
    return false;
}