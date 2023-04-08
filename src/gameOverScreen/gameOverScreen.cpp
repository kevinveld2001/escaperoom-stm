#include "gameOverScreen.h"
#include <global.h>

void GameOverScreen::setup() {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Game Over");
    tm.setLEDs(255 << 8);
}

void GameOverScreen::loop() {
    //stop main loop
    while(true){}
}