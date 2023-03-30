#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "global.h"
#include "asteroidGame/asteroidGame.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(A0, INPUT);

  // asteroidGame
  bool wonAsteroidGame = false;
  while (!wonAsteroidGame)
  {
    AsteroidGame* asteroidGame;
    wonAsteroidGame = asteroidGame->play();
    delete asteroidGame;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("You won!");
  

}

void loop() {}