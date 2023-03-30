#pragma once
#include "rocket/rocket.h"
#include "asteroids/asteroids.h"
#include "music/music.h"

class AsteroidGame {
private:
    Rocket rocket;
    Music music;
public:
    /**
     * returns a boolean to indicate game is won or lost
    */
    bool play();
    ~AsteroidGame() {
        delete[] &rocket;
        delete[] &music;
    };
};