#include "menu.h"
#include <global.h>
#include "./utils/buttons/buttons.h"
#include "utils/counter/counter.h"

byte arrow[] = {
  B00000,
  B00000,
  B11000,
  B11110,
  B11110,
  B11000,
  B00000,
  B00000
};

void setMode(u_int8_t mode) {
    gameDifficulty = mode;

    lcd.setCursor(0, 0);
    lcd.write(mode==0? 0: ' ');
    lcd.setCursor(0, 1);
    lcd.write(mode==1? 0: ' ');
}

void Menu::setup() {

    lcd.createChar(0, arrow);

    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("easy");
    lcd.setCursor(1, 1);
    lcd.print("hard");

    lcd.setCursor(6, 0);
    lcd.print("|Press '>'");
    lcd.setCursor(6, 1);
    lcd.print("|to start");

    setMode(0);
};


void Menu::loop() {

    if (areButtonsPressedEvent(0b00000001, true) && gameDifficulty == 1) {
        setMode(0);
    }

    if (areButtonsPressedEvent(0b00000010, true) && gameDifficulty == 0) {
        setMode(1);
    }

    if (areButtonsPressedEvent(0b00001100, false)) {
        nextLevel();
        startCounter();
    }

    buttonScanLoop();
};
