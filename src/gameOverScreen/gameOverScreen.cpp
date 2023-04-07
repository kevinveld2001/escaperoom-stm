#include "gameOverScreen.h"
#include <global.h>

void GameOverScreen::setup() {
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Game Over");
}

void GameOverScreen::loop() {
    //stop main loop
    while(true){}
}