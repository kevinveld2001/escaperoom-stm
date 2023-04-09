#include "simonSaysGame.h"
#include "../utils/buttons/buttons.h"
#include <global.h>

u_int8_t levelNeeded = 8;

int level = 0;
void printLevel() {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Simon Says");
    lcd.setCursor(6, 1);
    lcd.print(level );
    lcd.setCursor(7, 1);
    lcd.print("/");
    lcd.print(levelNeeded);
}

u_int8_t gameLevel[8]; 
void addRandomStepToGame() {
    gameLevel[level] = B00000001 << random(0, 4);
    level++;
}

long ledOnSince = 0;
bool ledOn = false;
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
    tone(buzzer_pin, note, 300);
    ledOnSince = millis();
    ledOn = true;
}

int letToPrint = 0;
bool printLets = false;
long lastPrintMillis = 0;

void printGameLevel() {
    printLets = true;
}

uint8_t pressIndex = 0;

void SimonSaysGame::setup() {
    level = 0;
    pressIndex = 0;
    if (gameDifficulty == 0) levelNeeded = 8;
    if (gameDifficulty == 1) levelNeeded = 10;
    addRandomStepToGame();
    printLevel();
    printGameLevel();
}

bool waitCheck = false;
long waitSince = 0;
int waitTime = 0; 
void wait(int time) {
    waitTime = time;
    waitSince = millis();
    waitCheck = true;
}


int gameover = 0;
void SimonSaysGame::loop() {
    if (waitCheck) {
        if (waitSince + waitTime < millis()) {
            waitCheck = false;
            printGameLevel();
        }
        return;
    }

    if (ledOn) {
        if (ledOnSince + 300 < millis()) {
            tm.setLEDs(0);
            ledOn = false;
        }
        return;
    }

    if (level == levelNeeded) {
        nextLevel();
        return;
    }

    if (gameover == 1) {
        tm.setLEDs(0);
        gameover = 2;
        wait(1500);
        return;
    }

    if (gameover == 2) {
        gameover = 0;
        setGameOver();
        return;
    }

    if (printLets) {
        if (lastPrintMillis + 1000 < millis()) {
            lastPrintMillis = millis();
            displayLed(gameLevel[letToPrint]);
            letToPrint++;
            if (letToPrint == level) {
                printLets = false;
                letToPrint = 0;
            }
        }
        return;
    }
    

    if (pressIndex == level) {
        addRandomStepToGame();
        printLevel();
        if (level != levelNeeded) 
            printGameLevel();

        pressIndex = 0;
        wait(1000);
        return;
    }

    if (areButtonsPressedEvent(gameLevel[pressIndex], true)) {
        pressIndex++;
        displayLed(gameLevel[pressIndex - 1]);
    } else if (areButtonsPressedEvent(~gameLevel[pressIndex], false)) {
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("Game Over");
        lcd.setCursor(3, 1);
        lcd.print("Score: ");
        lcd.print(level);

        tm.setLEDs(255 << 8);
        tone(buzzer_pin, 1000, 500);
        gameover = 1;
        wait(500);
        return;
    }

    buttonScanLoop();
}
