#include "rocket.h"
#include "../../global.h"
#include "../asteroids/asteroids_level.h";

  byte rocket[] = {
      B11000,
      B01111,
      B01111,
      B11000,
  };

  byte asteroid[] = {
      B01110,
      B11110,
      B01111,
      B00100
  };

  byte nothing[] = {
      B00000,
      B00000,
      B00000,
      B00000
  };

bool isOverlaping = false;
bool Rocket::isOverlapingAsteroid(uint8_t pos) {
  if (!checkOverlaping) return isOverlaping;
  checkOverlaping = false;
  for (int i = 0; i < levelSize; i++) {
    if (!asteroids[i].outOfScreen
      && asteroids[i].x == 0
      && asteroids[i].y&1 != pos&1) {
      isOverlaping = true;
      return true;
    }
  }
  isOverlaping = false;
  return false;
}


void Rocket::drawRocket() {
  uint8_t pos = 4 - map(analogRead(A0), 0, 1024, 1, 5);

  byte rocket_char[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};

  for (int i = 0; i < 4; i++) {
    rocket_char[i] |= pos&1? (isOverlapingAsteroid(pos)?asteroid[i]:nothing[i]): rocket[i];
  }
  for (int i = 4; i < 8; i++) {
    rocket_char[i] |= pos&1? rocket[i-4] : (isOverlapingAsteroid(pos)?asteroid[i-4]:nothing[i-4]);
  }


  lcd.createChar(1, rocket_char);

  if (pos != oldPos) {
    lcd.setCursor(0, 0);
    lcd.write(' ');
    lcd.setCursor(0, 1);
    lcd.write(' ');
    
    oldPos = pos;
  }

  lcd.setCursor(0, pos > 1);
  lcd.write(1);
}

uint8_t Rocket::getRocketPos() {
  return oldPos;
}
void Rocket::setCheckOverlaping(bool check) {
  checkOverlaping = check;
}