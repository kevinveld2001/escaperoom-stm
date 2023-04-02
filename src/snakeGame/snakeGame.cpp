#include "snakeGame.h"
#include <global.h>
#include "miniScreen.h"
#include "utils/buttons/buttons.h"

struct SnakeBody {
    int x;
    int y;
};

bool SnakeGame::play() {
    //setup
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print((char)255);
    lcd.setCursor(4, 1);
    lcd.print((char)255);
    lcd.setCursor(8, 0);
    lcd.print("Snake");

    miniScreenInit();

    SnakeBody b = {1, 1};
    long lastUpdate = millis();
    //loop
    while (true) {
        
        if (lastUpdate + 500 < millis()) {
            lastUpdate = millis();
            if (areButtonsPressed(0b00000001, true)) {
                miniScreenRemove(b.x, b.y);
                tm.setLEDs(B00000001 << 8);
                b.y--;
                miniScreenDraw(b.x, b.y);
            } else if (areButtonsPressed(0b00000010, true)) {
                miniScreenRemove(b.x, b.y);
                tm.setLEDs(B00000010 << 8);
                b.y++;
                miniScreenDraw(b.x, b.y);
            } else if (areButtonsPressed(0b00000100, true)) {
                miniScreenRemove(b.x, b.y);
                tm.setLEDs(B00000100 << 8);
                b.x--;
                miniScreenDraw(b.x, b.y);
            } else if (areButtonsPressed(0b00001000, true)) {
                miniScreenRemove(b.x, b.y);
                tm.setLEDs(B00001000 << 8);
                b.x++;
                miniScreenDraw(b.x, b.y);
            }
        }
        
        
        buttonScanLoop();
    }

    return true;
}