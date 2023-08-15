#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin(16,2);
  lcd.backlight();
  lcd.clear();
  
  //print welcome message
  lcd.setCursor(4,0);lcd.print("Welcome");
  delay(2000);
  lcd.clear();

  lcd.setCursor(5,0);
  lcd.print("Keels");
  lcd.setCursor(3,1);
  lcd.print("Katubedda");
  delay(2000);
  lcd.clear();
}

//method to print name of the item
void SetName(char namee){
  lcd.setCursor(0,0);
  lcd.print(namee);
}

//method to print quantity
void SetQuantity(char quantity){
  lcd.setCursor(0,1);
  lcd.print(quantity);
}

//method to print price of the item
void SetPrice(char price){
  lcd.setCursor(11,1);lcd.print(price);
}

int index=1;
void loop() {
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):

if(Serial.available()){
  char message=Serial.read();
  
  //code to clear the display
  if(message=="Clear" || message=="clear"){
    lcd.clear();
  }
  
  else{
    if(index==1){
      SetName(message);
      index=index+1;
    }
    if(index==2){
      SetQuantity(message);
      index=index+1;
    }
    if(index==3){
      SetPrice(message);
      index=1;
    } }

} }
