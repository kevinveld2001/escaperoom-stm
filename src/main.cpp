#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "global.h"
#include "asteroidGame/asteroidGame.h"
#include "simonSaysGame/simonSaysGame.h"
#include "snakeGame/snakeGame.h"
#include "numberStationGame/numberStationGame.h"


LiquidCrystal_I2C lcd(0x27, 16, 2);
TM1638plus tm(TM_STROBE, TM_CLOCK, TM_DIO);

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

  tm.displayBegin();

  pinMode(A0, INPUT);

  //A5 is reading static noise, so we use it to seed the random number generator
  pinMode(A5, INPUT);
  randomSeed(analogRead(A5));

  // asteroidGame
  bool wonAsteroidGame = true;
  bool wonSimonGame = true;
  bool wonSnakeGame = false;
  bool wonNumberStationGame = false;


  while (!wonAsteroidGame)
  {
    printLevel(1, 3, "Asteroids");
    AsteroidGame* asteroidGame;
    wonAsteroidGame = asteroidGame->play();
    delete asteroidGame;
  }

  // simonGame
  while (!wonSimonGame)
  {
    printLevel(2, 3, "Simon Says");
    SimonSaysGame* simonGame;
    wonSimonGame = simonGame->play();
    delete simonGame;
  }

  // snakeGame
  while (!wonSnakeGame)
  {
    printLevel(3, 5, "Snake");
    SnakeGame* snakeGame;
    wonSnakeGame = snakeGame->play();
    delete snakeGame;
  }

  // numberStationGame
  while (!wonNumberStationGame)
  {
    printLevel(4, 1, "Number Station");
    NumberStationGame* numberStationGame;
    wonNumberStationGame = numberStationGame->play();
    delete numberStationGame;
  }

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("You won!");
  

}

void loop() {}