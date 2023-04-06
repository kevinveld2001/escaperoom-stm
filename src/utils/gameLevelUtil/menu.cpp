#include "menu.h"
#include <global.h>
#include "./utils/buttons/buttons.h"

int counter = 0;

void Menu::setup() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("menu");
    counter = 0;
};


void Menu::loop() {

    if (areButtonsPressedEvent(0b00000001, true)) {
        counter++;
        lcd.setCursor(0, 1);
        lcd.printf("%03d", counter);
    }
    if (areButtonsPressedEvent(0b00000010, true)) {
        setGameOver();
    }

    if (areButtonsPressedEvent(0b00000100, true)) {
        nextLevel();
        return;
    }
    extern int currentLevelIndex;
    if (areButtonsPressedEvent(0b00001000, true)) {
        currentLevelIndex++;
        nextLevel();
        return;
    }

    buttonScanLoop();
};
