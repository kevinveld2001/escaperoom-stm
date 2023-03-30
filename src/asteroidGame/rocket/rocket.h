#pragma once
#include <Arduino.h>

class Rocket {
private:
    uint8_t oldPos = 0;
    bool checkOverlaping = true;
    bool isOverlapingAsteroid(uint8_t pos);
public:
    void drawRocket();
    uint8_t getRocketPos();
    void setCheckOverlaping(bool check);
};


