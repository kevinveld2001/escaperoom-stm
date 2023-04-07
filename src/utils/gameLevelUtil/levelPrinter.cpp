#include <global.h>
#include "levelPrinter.h"

byte lostlife[] = {
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B01010,
  B00100,
  B00100
};

byte fulllife[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B01110,
  B00100,
  B00100
};

void printLevel(int level, int x, String gameName, u_int8_t lifes) {
  lcd.clear();
  lcd.setCursor(x, 1);
  lcd.print(gameName);
  if (level <= 0) return;
  lcd.setCursor(0, 0);
  lcd.print("Level ");
  lcd.print(level);
  
  lcd.createChar(1, lostlife);
  lcd.createChar(2, fulllife);

  lcd.setCursor(11, 0);
  lcd.write((byte)(lifes>4) + 1);
  lcd.write((byte)(lifes>3) + 1);
  lcd.write((byte)(lifes>2) + 1);
  lcd.write((byte)(lifes>1) + 1);
  lcd.write((byte)(lifes>0) + 1);

}