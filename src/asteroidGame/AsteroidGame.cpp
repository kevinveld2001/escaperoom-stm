#include "AsteroidGame.h"
#include <global.h>

bool AsteroidGame::play() {
    //setup
    lcd.clear();
    setupAsteroids();
    long lastMilis = millis();
    Rocket rocket;
    
    //loop
    while (true)
    {
        if (!checkGameOver(rocket.getRocketPos())) {
            if (millis() > lastMilis + 500) {
                lastMilis = millis();
                drawAsteroids();
            }
            
            rocket.drawRocket();
        } else {
            return false;
        }
    }

    return true;
}