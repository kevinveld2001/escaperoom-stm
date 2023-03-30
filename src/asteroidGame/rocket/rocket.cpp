#include "rocket.h"
#include "../../global.h"

byte rocket_l[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B01111,
  B01111,
  B11000
};

byte rocket_u[] = {
  B11000,
  B01111,
  B01111,
  B11000,
  B00000,
  B00000,
  B00000,
  B00000
};


void Rocket::drawRocket() {
  uint8_t pos = 4 - map(analogRead(A0), 0, 1024, 1, 5);

  lcd.createChar(1, pos&1? rocket_l: rocket_u);

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