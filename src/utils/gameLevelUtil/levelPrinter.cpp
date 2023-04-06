#include <global.h>
#include "levelPrinter.h"

void printLevel(int level, int x, String gameName) {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Level ");
  lcd.print(level);
  lcd.setCursor(x, 1);
  lcd.print(gameName);
}