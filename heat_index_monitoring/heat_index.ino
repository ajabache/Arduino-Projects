#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

dht DHT;
#define DHT11_PIN 7
#define BUZZER_PIN 8

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.begin();// Initialize the LCD

  lcd.backlight();   // Turn on the backlight
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);

  if (DHT.temperature >= 27 && DHT.temperature <= 31 && DHT.humidity >=45) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.print(DHT.temperature);
    lcd.setCursor(8, 0);
    lcd.print("H=");
    lcd.print(DHT.humidity);
  
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    lcd.setCursor(4, 1);
    lcd.print("CAUTION");
    noTone(BUZZER_PIN);
  }
  else if (DHT.temperature >= 32 && DHT.temperature <=35 &&  DHT.humidity >= 45) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.print(DHT.temperature);
    lcd.setCursor(8, 0);
    lcd.print("H=");
    lcd.print(DHT.humidity);
  
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    lcd.setCursor(0, 1);
    lcd.print("EXTREME CAUTION");
  }
  else if (DHT.temperature >= 36 &&  DHT.temperature <=40 &&  DHT.humidity >= 45) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.print(DHT.temperature);
    lcd.setCursor(8, 0);
    lcd.print("H=");
    lcd.print(DHT.humidity);
  
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    lcd.setCursor(4, 1);
    lcd.print("DANGER");

    tone(BUZZER_PIN, 523, 300);
    delay(300);
    noTone(BUZZER_PIN);
    delay(100);
  }
  else if (DHT.temperature >= 41 &&  DHT.humidity >= 45) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.print(DHT.temperature);
    lcd.setCursor(8, 0);
    lcd.print("H=");
    lcd.print(DHT.humidity);
  
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    lcd.setCursor(1, 1);
    lcd.print("EXTREME DANGER");

    tone(BUZZER_PIN, 600, 500);
    delay(300);
    noTone(BUZZER_PIN);
    delay(100);
  }
  else if (DHT.temperature <= 27) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.print(DHT.temperature);
    lcd.setCursor(8, 0);
    lcd.print("H=");
    lcd.print(DHT.humidity);
  
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    lcd.setCursor(2, 1);
    lcd.print("NORMAL TEMP");
  }
  delay(1000);
}

