#include "menu.h"
#include <global.h>
#include "./utils/buttons/buttons.h"

void Menu::setup() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("> easy");
    lcd.setCursor(2, 1);
    lcd.print("hard");

    gameDifficulty = 0;
};


void setMode(u_int8_t mode) {
    gameDifficulty = mode;

    lcd.setCursor(0, 0);
    lcd.write(mode==0? '>': ' ');
    lcd.setCursor(0, 1);
    lcd.write(mode==1? '>': ' ');
}


void Menu::loop() {

    if (areButtonsPressedEvent(0b00000001, true) && gameDifficulty == 1) {
        setMode(0);
    }

    if (areButtonsPressedEvent(0b00000010, true) && gameDifficulty == 0) {
        setMode(1);
    }

    if (areButtonsPressedEvent(0b00001100, false)) {
        nextLevel();
    }

    buttonScanLoop();
};
