#include<dht.h>
dht DHT;
#define DHT11_PIN 7
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define buzzer 8 
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 lcd.begin();
 pinMode (11,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (buzzer,OUTPUT);

}

void loop() {

  if (DHT.temperature >= 31 && DHT.humidity >=50){
     int chk = DHT.read11(DHT11_PIN);
     lcd.clear();
  lcd.backlight();
   lcd.setCursor(0, 0);
 lcd.print("T=");
 lcd.print(DHT.temperature);
  lcd.setCursor(8, 0);
  lcd.print("H=");
 lcd.print(DHT.humidity);
  delay (1000);
    digitalWrite (12,HIGH);
    digitalWrite (11,LOW);
    lcd.setCursor(4, 1);
    lcd.print ("WARNING!");
  
  tone(buzzer,523,300);
    delay(300);
    noTone(buzzer);
    delay(100);
    

  
}
  else if (DHT.temperature <=27){
     int chk = DHT.read11(DHT11_PIN);
  lcd.backlight();
   lcd.setCursor(0, 0);
 lcd.print("T=");
 lcd.print(DHT.temperature);
  lcd.setCursor(8, 0);
  lcd.print("H=");
 lcd.print(DHT.humidity);
  delay (1000);
    digitalWrite (11,HIGH);
    digitalWrite (12,LOW);
    lcd.setCursor(3, 1);
    lcd.print ("NORMAL TEMP");
    noTone(buzzer);
}
}
