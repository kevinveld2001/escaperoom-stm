#pragma once


class SnakeGame {
private:
    void spawnFood();
    bool moveSnake();
    bool isColision(int x, int y);
public:
    /**
     * returns a boolean to indicate game is won or lost
    */
    bool play();
};