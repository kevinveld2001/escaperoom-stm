#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "global.h"
#include "utils/gameLevelUtil/gameLevelUtil.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
TM1638plus tm(TM_STROBE, TM_CLOCK, TM_DIO);
u_int8_t gameDifficulty = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  tm.displayBegin();

  pinMode(A0, INPUT);

  //A5 is reading static noise, so we use it to seed the random number generator
  pinMode(A5, INPUT);
  randomSeed(analogRead(A5));
  
  initGame();
}

void loop() {
  runLoop();
}