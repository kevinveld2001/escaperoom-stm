#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "global.h"
#include "asteroidGame/asteroidGame.h"
#include "simonSaysGame/simonSaysGame.h"
#include "snakeGame/snakeGame.h"
#include "numberStationGame/numberStationGame.h"


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(A0, INPUT);

  // asteroidGame
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Level 1");
  lcd.setCursor(3, 1);
  lcd.print("Asteroids");
  delay(2000);
  bool wonAsteroidGame = false;
  while (!wonAsteroidGame)
  {
    AsteroidGame* asteroidGame;
    wonAsteroidGame = asteroidGame->play();
    delete asteroidGame;
  }

  // simonGame
    lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Level 2");
  lcd.setCursor(3, 1);
  lcd.print("Simon Says");
  delay(2000);
  bool wonSimonGame = false;
  while (!wonSimonGame)
  {
    SimonSaysGame* simonGame;
    wonSimonGame = simonGame->play();
    delete simonGame;
  }

  // snakeGame
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Level 3");
  lcd.setCursor(5, 1);
  lcd.print("Snake");
  delay(2000);
  bool wonSnakeGame = false;
  while (!wonSnakeGame)
  {
    SnakeGame* snakeGame;
    wonSnakeGame = snakeGame->play();
    delete snakeGame;
  }

  // numberStationGame
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Level 4");
  lcd.setCursor(1, 1);
  lcd.print("Number Station");
  delay(2000);
  bool wonNumberStationGame = false;
  while (!wonNumberStationGame)
  {
    NumberStationGame* numberStationGame;
    wonNumberStationGame = numberStationGame->play();
    delete numberStationGame;
  }

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("You won!");
  

}

void loop() {}