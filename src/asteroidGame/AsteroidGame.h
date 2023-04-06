#pragma once
#include "rocket/rocket.h"
#include "asteroids/asteroids.h"
#include "music/music.h"
#include "./utils/gameLevelUtil/playable.h"

class AsteroidGame: public Playable {
private:
    Rocket rocket;
    Music music;
    long lastMilis = millis();
public:
    void setup() override;
    void loop() override;

    ~AsteroidGame() {
        delete[] &rocket;
        delete[] &music;
    };
};