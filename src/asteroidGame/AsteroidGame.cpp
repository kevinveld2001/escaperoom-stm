#include "AsteroidGame.h"
#include <global.h>


bool AsteroidGame::play() {
    //setup
    lcd.clear();
    setupAsteroids();
    long lastMilis = millis();
    Rocket rocket;
    Music music;
    
    //loop
    while (true)
    {
        if (!checkGameOver(rocket.getRocketPos())) {
            if (millis() > lastMilis + 500) {
                lastMilis = millis();
                drawAsteroids();
                rocket.setCheckOverlaping(true);
                // check if game is won
                if (noAsteroidsLeft()) {
                    music.stopMusic();
                    return true;
                }
            }
            
            rocket.drawRocket();
            music.playMusic();
        } else {
            music.stopMusic();
            delay(3000);
            return false;
        }
    }
}