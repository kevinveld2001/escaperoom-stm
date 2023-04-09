#include "numberStationGame.h"
#include <global.h>
#include "utils/buttons/buttons.h"
#include "utils/reverseBits/reverseBits.h"

char randomNumber = '0';
int randomNumberInt = 0;
uint8_t typedNumber = 0;

void NumberStationGame::setup() {
    radioSetup();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Number Station");
    lcd.setCursor(0, 1);
    lcd.print("Listen to radio");

    randomNumberInt = random(1, 9);
    randomNumber = '0' + randomNumberInt;

    typedNumber = 0;
    tm.setLEDs(typedNumber << 8);
}

long lastSend = 0;

void NumberStationGame::loop() {
    if (lastSend + 2000 < millis()) {
        lastSend = millis();
        radioSendMorseCode(randomNumber);
    }
    

    if (areButtonsPressedEvent(0b11111111, false)) {
        typedNumber ^= getButtons();
        tm.setLEDs(typedNumber << 8);
        if (reverse(typedNumber) == randomNumberInt) {
            radioShutdown();
            nextLevel();
        }
    }

    radioLoop();
    buttonScanLoop();
}