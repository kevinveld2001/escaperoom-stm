#pragma once
#include "./utils/gameLevelUtil/playable.h"

class SnakeGame: public Playable {
private:
    void spawnFood();
    bool moveSnake();
    bool isColision(int x, int y);
public:
    void setup() override;
    void loop() override;
};