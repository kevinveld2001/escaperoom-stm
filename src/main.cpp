#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "global.h"
#include "asteroidGame/asteroidGame.h"
#include "simonSaysGame/simonSaysGame.h"
#include "snakeGame/snakeGame.h"
#include "numberStationGame/numberStationGame.h"


LiquidCrystal_I2C lcd(0x27, 16, 2);

void printLevel(int level, int x, String gameName) {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Level ");
  lcd.print(level);
  lcd.setCursor(x, 1);
  lcd.print(gameName);
  delay(2000);
}

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(A0, INPUT);

  // asteroidGame
  printLevel(1, 3, "Asteroids");
  bool wonAsteroidGame = false;
  while (!wonAsteroidGame)
  {
    AsteroidGame* asteroidGame;
    wonAsteroidGame = asteroidGame->play();
    delete asteroidGame;
  }

  // simonGame
  printLevel(2, 3, "Simon Says");
  bool wonSimonGame = false;
  while (!wonSimonGame)
  {
    SimonSaysGame* simonGame;
    wonSimonGame = simonGame->play();
    delete simonGame;
  }

  // snakeGame
  printLevel(3, 5, "Snake");
  bool wonSnakeGame = false;
  while (!wonSnakeGame)
  {
    SnakeGame* snakeGame;
    wonSnakeGame = snakeGame->play();
    delete snakeGame;
  }

  // numberStationGame
  printLevel(4, 1, "Number Station");
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