#include "AsteroidGame.h"
#include <global.h>

int gameOverLight = 0;

bool doWait = false;
int timeToWait = 0; 
void waitTime(int time) {
    timeToWait = time + millis();
    doWait = true;
}

void AsteroidGame::setup() {
    lcd.clear();
    setupAsteroids();
    Rocket rocket;
    Music music;
    gameOverLight = 0;
}

void AsteroidGame::loop() {
    if (timeToWait > millis()) return;

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
        if (gameOverLight < 10) {
            if (gameOverLight&1) {
                lcd.backlight();
            } else {
                lcd.noBacklight();
            }
            gameOverLight++;
            waitTime(100);
            return;
        }

        waitTime(200);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  GAME OVER!!! ");
        music.stopMusic();
        waitTime(3000);
        setGameOver();
    }
}
