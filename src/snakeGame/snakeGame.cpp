#include "snakeGame.h"
#include <global.h>
#include "miniScreen.h"
#include "utils/buttons/buttons.h"

struct SnakeBody {
    int x;
    int y;
};

#define SNAKE_SIZE 100

SnakeBody snakeBodyBuffer[SNAKE_SIZE];
int headIndex;
int tailIndex;
u_int8_t direction;
u_int8_t grow = 0;

void moveSnake() {
    if (grow == 0) {
        SnakeBody oldSnakeBody = snakeBodyBuffer[tailIndex];
        miniScreenRemove(oldSnakeBody.x, oldSnakeBody.y);
        tailIndex = (tailIndex + 1) % SNAKE_SIZE;
    } else {
        grow--;
    }

    SnakeBody oldHead = snakeBodyBuffer[headIndex];
    headIndex = (headIndex + 1) % SNAKE_SIZE;

    int moveX = 0;
    int moveY = 0;
    if (direction & 0b00001000) moveX = 1;
    if (direction & 0b00000100) moveX = -1;
    if (direction & 0b00000010) moveY = 1;
    if (direction & 0b00000001) moveY = -1;

    snakeBodyBuffer[headIndex] = {oldHead.x + moveX, oldHead.y + moveY};
    miniScreenDraw(snakeBodyBuffer[headIndex].x, snakeBodyBuffer[headIndex].y);
}


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

    snakeBodyBuffer[0] = {1, 0};
    snakeBodyBuffer[1] = {2, 0};
    snakeBodyBuffer[2] = {3, 0};

    //draw initial snake
    for (int i = 0; i < 3; i++) {
        miniScreenDraw(snakeBodyBuffer[i].x, snakeBodyBuffer[i].y);
    }

    headIndex = 3;
    tailIndex = 0;

    direction = 0b00001000;
    
    long lastUpdate = millis();
    //loop
    while (true) {
        
        tm.setLEDs(direction << 8);;
        uint8_t newDirection = getButtons() & 0b00001111;
        if (newDirection != 0) {
            direction = newDirection;
        }

        if (lastUpdate + 500 < millis()) {
            lastUpdate = millis();
            moveSnake();
        }

        if (areButtonsPressedEvent(0b10000000, true)) {
            grow = 3;
        }
        
        
        buttonScanLoop();
    }

    return true;
}