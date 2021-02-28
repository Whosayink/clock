#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

#define dhtpin 2
#define dhttype DHT11
DHT dht(dhtpin, dhttype);

LiquidCrystal_I2C lcd(0x27,16,2);
virtuabotixRTC myRTC(6, 8, 7);


byte celc[8] = {
  B00010,
  B00101,
  B00010,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};



void setup() {
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  lcd.init();
  lcd.backlight();
  dht.begin();
  lcd.createChar(0,celc);
  //myRTC.setDS1302Time(0, 51, 20, 7, 28, 2, 2021);
}

void loop() {
  myRTC.updateTime();
  lcd.setCursor(0,0);
  lcd.print("Saat: ");
  lcd.print(myRTC.hours);
  lcd.print(" : ");
  lcd.print(myRTC.minutes);
  lcd.setCursor(0,1);
  lcd.print(dht.readTemperature());
  lcd.write(0);
  lcd.print("C Nem: %");
  lcd.print(int(dht.readHumidity()));
  delay(1000);

}
