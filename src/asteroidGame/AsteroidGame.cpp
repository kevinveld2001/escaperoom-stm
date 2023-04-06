#include "AsteroidGame.h"
#include <global.h>

void AsteroidGame::setup() {
    lcd.clear();
    setupAsteroids();
    Rocket rocket;
    Music music;
}

void AsteroidGame::loop() {
    if (!checkGameOver(rocket.getRocketPos())) {
        if (millis() > lastMilis + 500) {
            lastMilis = millis();
            drawAsteroids();
            //check if game is won
            if (noAsteroidsLeft()) {
                music.stopMusic();
                nextLevel();
                return;
            }
        }
        
        rocket.drawRocket();
        music.playMusic();
    } else {
        music.stopMusic();
        delay(3000);
        setGameOver();
    }
}
