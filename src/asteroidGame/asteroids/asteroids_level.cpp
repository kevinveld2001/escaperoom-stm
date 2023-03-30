#include "asteroids.h"
#include "asteroids_level.h"

int levelSize = 15;
Asteroid* asteroids = new Asteroid[levelSize];

void setLevel() {
     asteroids = new Asteroid[levelSize]{
        {1, 8, sprite_full},

        {0, 10, sprite_high},
        {1, 10, sprite_low},

        {0, 11, sprite_full},

        {0, 12, sprite_high},

        {1, 13, sprite_low},

        {0, 14, sprite_high},
        {1, 14, sprite_high},

        {0, 17, sprite_low},
        {1, 17, sprite_high},

        {0, 19, sprite_high},

        {0, 20, sprite_low},
        {1, 20, sprite_low},

        {1, 21, sprite_low},

        {1, 22, sprite_high},
    };
}