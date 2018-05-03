#include <LiquidCrystal.h>

LiquidCrystal lcd(52, 50, 48, 46, 44, 42);

void setup(){
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop(){
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
