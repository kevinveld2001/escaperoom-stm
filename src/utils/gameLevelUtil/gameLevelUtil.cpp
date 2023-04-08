#include <global.h>
#include "playable.h"
#include "menu.h"
#include "levelPrinter.h"
#include "utils/counter/counter.h"

#include "gameOverScreen/gameOverScreen.h"
#include "asteroidGame/asteroidGame.h"
#include "simonSaysGame/simonSaysGame.h"
#include "snakeGame/snakeGame.h"

//define initGame
void initGame();

Playable* currentLevel = new Menu();
int currentLevelIndex = 0;

u_int8_t lifes = 5;

void nextLevel() {
    currentLevelIndex++;
    initGame();
}

void timeUp() {
    currentLevelIndex = -1;
    initGame();
}

void setGameOver() {
    lifes--;
    if (lifes <= 0) {
        currentLevelIndex = -1;
    }
    initGame();
}
long timeTillGameStart = 0;
bool hasRunSetup = false;

void initGame() {
    delete currentLevel;

    switch (currentLevelIndex)
    {
    case -1:
        currentLevel = new GameOverScreen();
        hasRunSetup = false;
        return;
        break;
    case 0:
        printLevel(0, 0, "Escape the room", lifes);
        currentLevel = new Menu();
        break;
    case 1:
        printLevel(1, 3, "Asteroids", lifes);
        currentLevel = new AsteroidGame();
        break;
    case 2:
        printLevel(2, 3, "Simon Says", lifes);
        currentLevel = new SimonSaysGame();
        break;
    case 3:
        printLevel(3, 5, "Snake", lifes);
        currentLevel = new SnakeGame();
        break;
    case 4:
        printLevel(4, 1, "Number Station", lifes);
        break;
    }
    timeTillGameStart = millis() + 2000;
    hasRunSetup = false;
}

void runLoop() {
    displayCounter();
    if (millis() < timeTillGameStart) {
        return;
    }
    if (!hasRunSetup) {
        currentLevel->setup();
        hasRunSetup = true;
    }
    currentLevel->loop();
}