#include "simonSaysGame.h"
#include "../utils/buttons/buttons.h"
#include <global.h>

int level = 0;
void printLevel() {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Simon Says");
    lcd.setCursor(6, 1);
    lcd.print(level );
    lcd.setCursor(7, 1);
    lcd.print("/8");
}

u_int8_t gameLevel[8]; 
void addRandomStepToGame() {
    gameLevel[level] = B00000001 << random(0, 4);
    level++;
}

void displayLed(u_int8_t leds) {
    tm.setLEDs(leds << 8);
    int note = 0;
    switch (leds) {
        case B00000001:
            note = 300;
            break;
        case B00000010:
            note = 500;
            break;
        case B00000100:
            note = 700;
            break;
        case B00001000:
            note = 900;
            break;
    }
    tone(buzzer_pin, note, 500);
    delay(500);
    tm.setLEDs(0);
    
}

void printGameLevel() {
    for (int i = 0; i < level; i++) {
        displayLed(gameLevel[i]);
        delay(500);
    }
}

uint8_t pressIndex = 0;

void SimonSaysGame::setup() {
    level = 0;
    pressIndex = 0;
    addRandomStepToGame();
    printLevel();
    printGameLevel();
}

void SimonSaysGame::loop() {
    if (level == 8) {
        nextLevel();
    }
    if (areButtonsPressedEvent(gameLevel[pressIndex], true)) {
        pressIndex++;
        displayLed(gameLevel[pressIndex - 1]);
        if (pressIndex == level) {
            delay(1000);
            addRandomStepToGame();
            printLevel();
            if (level != 8) 
                printGameLevel();

            pressIndex = 0;
        }
    } else if (areButtonsPressedEvent(~gameLevel[pressIndex], false)) {
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("Game Over");
        lcd.setCursor(3, 1);
        lcd.print("Score: ");
        lcd.print(level);

        tm.setLEDs(255 << 8);
        tone(buzzer_pin, 1000, 500);
        delay(500);
        tm.setLEDs(0);
        delay(1000);
        setGameOver();
    }

        buttonScanLoop();
}
