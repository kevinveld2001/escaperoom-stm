#include "simonSaysGame.h"
#include "../utils/buttons/buttons.h"
#include <global.h>
int counter = 0;
bool SimonSaysGame::play() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(counter);

    
    while (true) {
        if (areButtonsPressedEvent(B00000001)) {
            counter++;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(counter);
            
        }

        buttonScanLoop();
    }
    return true;
};