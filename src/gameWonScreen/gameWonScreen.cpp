#include "gameWonScreen.h"
#include <global.h>

void GameWonScreen::setup() {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("you won!!!!");
    tm.setLEDs(255 << 8);
}

void GameWonScreen::loop() {
    //stop main loop
    while(true){}
}