#include <LiquidCrystal_I2C.h>
#define up 11
#define down 10
#define Y 9
#define B 8

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Press");
  lcd.setCursor(6, 1);
  lcd.print("start!");
  
}
void loop(){
  if(digitalRead(Y) == 1) {
    start();
  }
}
void start() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Hello");
  lcd.setCursor(6, 1);
  lcd.print("Wold!");
}
