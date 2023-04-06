#include <global.h>
#include "playable.h"
#include "menu.h"
#include "levelPrinter.h"

#include "./asteroidGame/asteroidGame.h"
#include "./simonSaysGame/simonSaysGame.h"
#include "./snakeGame/snakeGame.h"

//define initGame
void initGame();

Playable* currentLevel = new Menu();
int currentLevelIndex = 0;

void nextLevel() {
    currentLevelIndex++;
    initGame();
}

void setGameOver() {
    initGame();
}
long timeTillGameStart = 0;
bool hasRunSetup = false;

void initGame() {
    delete currentLevel;

    switch (currentLevelIndex)
    {
    case 0:
        printLevel(0, 0, "Escape the room");
        currentLevel = new Menu();
        break;
    case 1:
        printLevel(1, 3, "Asteroids");
        currentLevel = new AsteroidGame();
        break;
    case 2:
        printLevel(2, 3, "Simon Says");
        currentLevel = new SimonSaysGame();
        break;
    case 3:
        printLevel(3, 5, "Snake");
        currentLevel = new SnakeGame();
        break;
    case 4:
        printLevel(4, 1, "Number Station");
        break;
    }
    timeTillGameStart = millis() + 2000;
    hasRunSetup = false;
}

void runLoop() {
    if (millis() < timeTillGameStart) {
        return;
    }
    if (!hasRunSetup) {
        currentLevel->setup();
        hasRunSetup = true;
    }
    currentLevel->loop();
}