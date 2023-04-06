#include <global.h>
#include "playable.h"
#include "menu.h"
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

void initGame() {
    delete currentLevel;

    switch (currentLevelIndex)
    {
    case 0:
        currentLevel = new Menu();
        break;
    case 1:
        currentLevel = new AsteroidGame();
        break;
    case 2:
        currentLevel = new SimonSaysGame();
        break;
    case 3:
        currentLevel = new SnakeGame();
        break;
    }
    currentLevel->setup();
}

void runLoop() {
    currentLevel->loop();
}