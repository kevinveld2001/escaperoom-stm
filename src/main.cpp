#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "rocket/rocket.h"
#include "asteroids/asteroids.h"
#include "global.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();

  lcd.backlight();
  pinMode(A0, INPUT);

  setupAsteroids();
}

long lastMilis = 0;
void loop() {
  if (!checkGameOver(getRocketPos())) {
    if (millis() > lastMilis + 500) {
        lastMilis = millis();
        drawAsteroids();
    }
     
    drawRocket();
  }
}