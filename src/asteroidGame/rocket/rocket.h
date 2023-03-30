#pragma once
#include <Arduino.h>

class Rocket {
private:
    uint8_t oldPos = 0;
    
public:
    void drawRocket();
    uint8_t getRocketPos();
};


