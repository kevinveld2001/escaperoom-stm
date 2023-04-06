#include "snakeGame.h"
#include <global.h>
#include "miniScreen.h"
#include "utils/buttons/buttons.h"
#include <Arduino.h>

#define SNAKE_SIZE 100

struct SnakeBody {
    int x;
    int y;
};

int foodXpos = 0;
int foodYpos = 0;

int snakeLevel = 0;

SnakeBody snakeBodyBuffer[SNAKE_SIZE];
u_int8_t direction = 0b00000010;
u_int8_t grow = 0;
int headIndex = 2;
int tailIndex = 0;

void drawSnakeLevel() {
    lcd.setCursor(6, 1);
    lcd.printf("Level: %02d", snakeLevel);
}

struct Direction {
    int x;
    int y;
};

Direction bitesDirectionToStruct(u_int8_t bitesDirection) {
    Direction direction = {0, 0};
    if (bitesDirection & 0b00001000) direction.x = 1;
    if (bitesDirection & 0b00000100) direction.x = -1;
    if (bitesDirection & 0b00000010) direction.y = 1;
    if (bitesDirection & 0b00000001) direction.y = -1;
    return direction;
}


bool SnakeGame::moveSnake() {
    if (grow == 0) {
        SnakeBody oldSnakeBody = snakeBodyBuffer[tailIndex];
        miniScreenRemove(oldSnakeBody.x, oldSnakeBody.y);
        tailIndex = (tailIndex + 1) % SNAKE_SIZE;
    } else {
        grow--;
    }

    SnakeBody oldHead = snakeBodyBuffer[headIndex];
    headIndex = (headIndex + 1) % SNAKE_SIZE;
    Direction move = bitesDirectionToStruct(direction);

    if (isColision(oldHead.x + move.x, oldHead.y + move.y)) {
        return false;
    }
    if ((oldHead.x + move.x) == foodXpos && (oldHead.y + move.y) == foodYpos) {
        grow = 5;
        spawnFood();
        snakeLevel++;
        drawSnakeLevel();
    }

    snakeBodyBuffer[headIndex] = {oldHead.x + move.x, oldHead.y + move.y};
    miniScreenDraw(snakeBodyBuffer[headIndex].x, snakeBodyBuffer[headIndex].y);
    return true;
}

long lastUpdate = millis();
void SnakeGame::setup() {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print((char)255);
    lcd.setCursor(4, 1);
    lcd.print((char)255);
    lcd.setCursor(8, 0);
    lcd.print("Snake");

    miniScreenInit();

    //clear snake buffer
    for (int i = 0; i < SNAKE_SIZE; i++) {
        snakeBodyBuffer[i] = {0, 0};
    }

    snakeBodyBuffer[0] = {2, 2};    
    snakeBodyBuffer[1] = {2, 3};
    snakeBodyBuffer[2] = {2, 4};

    headIndex = 2;
    tailIndex = 0;
    direction = 0b00000010;
    grow = 0;
    snakeLevel = 0;
    drawSnakeLevel();

    //draw initial snake
    for (int i = 0; i < 3; i++) {
        miniScreenDraw(snakeBodyBuffer[i].x, snakeBodyBuffer[i].y);
    }

    spawnFood();

    lastUpdate = millis();
}

void SnakeGame::loop() {
    tm.setLEDs(direction << 8);;
    uint8_t newDirection = getButtons() & 0b00001111;
    if (newDirection != 0) {
        Direction dir = bitesDirectionToStruct(direction);
        Direction newDir = bitesDirectionToStruct(newDirection);
        if ((dir.x - newDir.x) != 0 && (dir.y - newDir.y) != 0) {
            direction = newDirection;
        }
    }

    if (lastUpdate + 500 < millis()) {
        lastUpdate = millis();
        if (!moveSnake()) {
            setGameOver();
        }
    }
    
    buttonScanLoop();
}

bool SnakeGame::isColision(int x, int y) {
    if (x < 0 || x > 19 || y < 0 || y > 15) return true;

    for (int i = 0; i < SNAKE_SIZE; i++) {

        //check if i is in snake if so set inSnakeCheck to true
        bool inSnakeCheck = false;

        if (headIndex < tailIndex) {
            if (i >= tailIndex || i <= headIndex) {
                inSnakeCheck = true;
            }
        } else {
            if (i >= tailIndex && i <= headIndex) {
                inSnakeCheck = true;
            }
        }

        if (inSnakeCheck && snakeBodyBuffer[i].x == x && snakeBodyBuffer[i].y == y) {
            return true;
        }
    }

    return false;
}

void SnakeGame::spawnFood() {
    foodXpos = random(4, 18);
    foodYpos = random(2, 14);

    miniScreenDraw(foodXpos, foodYpos);
}