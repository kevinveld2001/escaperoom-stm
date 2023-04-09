#include "numberStationGame.h"
#include <global.h>

void NumberStationGame::setup() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Number Station");
    lcd.setCursor(0, 1);
    lcd.print("Listen to radio");
}

void NumberStationGame::loop() {

}