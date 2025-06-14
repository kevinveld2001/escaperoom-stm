#include "asteroids.h"
#include "../../global.h"
#include "asteroids_level.h"

#define sprite_high 2
#define sprite_low 3
#define sprite_full 4

#include "asteroids_level.h"
#include "asteroids_sprites.h"

bool gameOver = false;

void setupAsteroids() {
    lcd.createChar(sprite_high, asteroid_h);
    lcd.createChar(sprite_low, asteroid_l);
    lcd.createChar(sprite_full, asteroid_full);
    setLevel();
    drawAsteroids();
    gameOver = false;
}
     
void drawAsteroids() {
    for (int i = 0; i < levelSize; i++) {
        Asteroid& asteroid = asteroids[i];        
        if (!asteroid.outOfScreen) {
            asteroid.x--;
            
            //remove last asteroid pos
            lcd.setCursor(asteroid.x + 1, asteroid.y);
            lcd.write(' ');

            if (asteroid.x < 0) {
                asteroid.outOfScreen = true;
            } else if (asteroid.x <= 16) {
                lcd.setCursor(asteroid.x, asteroid.y);
                lcd.write(asteroid.sprite);
            }
        }

    }
}


bool checkGameOver(u_int8_t rocketPos) {
    if (!gameOver) {
        for (int i; i < levelSize; i++) {
            if (asteroids[i].x == 0
                && asteroids[i].y == (rocketPos > 1)
                && (
                   asteroids[i].sprite == sprite_full
                   || (asteroids[i].sprite == sprite_high && !rocketPos&1)
                   || (asteroids[i].sprite == sprite_low && rocketPos&1)
                )) {
                gameOver = true;
            }
        }
    }
    return gameOver;
}


bool noAsteroidsLeft() {
    for (int i = 0; i < levelSize; i++) {
        if (!asteroids[i].outOfScreen) {
            return false;
        }
    }
    return true;
}