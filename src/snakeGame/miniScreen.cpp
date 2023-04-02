#include "miniScreen.h"

byte chars[2][4][8];

void miniScreenInit() {
    
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 4; x++) {
            for (int line = 0; line < 8; line++) {
                chars[y][x][line] = 0;
            }
            lcd.createChar(y * 4 + x, chars[y][x]);
            lcd.setCursor(x, y);
            lcd.write(y * 4 + x);
        }
    }
    
}

void miniScreenDraw(unsigned int x, unsigned int y) {
    int charX = x / 5;
    int charY = y / 8;
    chars[charY][charX][y%8] |= 0b10000 >> (x%5);
    lcd.createChar(charY * 4 + charX, chars[charY][charX]);
    lcd.setCursor(charX, charY);
    lcd.write(charY * 4 + charX);
}

void miniScreenRemove(unsigned int x, unsigned int y) {
    int charX = x / 5;
    int charY = y / 8;
    chars[charY][charX][y%8] &= ~(0b10000 >> (x%5));
    lcd.createChar(charY * 4 + charX, chars[charY][charX]);
    lcd.setCursor(charX, charY);
    lcd.write(charY * 4 + charX);
}