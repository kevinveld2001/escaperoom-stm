#include <global.h>
#include "levelPrinter.h"

void printLevel(int level, int x, String gameName) {
  lcd.clear();
  lcd.setCursor(x, 1);
  lcd.print(gameName);
  if (level == 0) return;
  lcd.setCursor(4, 0);
  lcd.print("Level ");
  lcd.print(level);
  
}