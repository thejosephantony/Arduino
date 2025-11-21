#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Boa tarde");
}

void loop() {
  unsigned long tempo = millis() / 1000; 

  lcd.setCursor(0, 1); 
  lcd.print(tempo);
  lcd.print("s   "); 


  if (tempo >= 5) {
    lcd.setCursor(0, 0);
    lcd.print("Olavo tem razao!");
  }

}
