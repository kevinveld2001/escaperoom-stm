#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


#define sprite_high 2
#define sprite_low 3
#define sprite_full 4

struct Asteroid
{
    int y;
    int x;
    uint8_t sprite;
    bool outOfScreen = false;
};

void setupAsteroids();

void drawAsteroids();

bool checkGameOver(u_int8_t rocketPos);

