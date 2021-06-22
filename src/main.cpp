#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x20, 16, 2);

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11     // DHT 11
#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
void debug(String str) {
#ifdef DEBUG
  	uint32_t now = millis();
  	Serial.printf("%07u.%03u: %s\n", now / 1000, now % 1000, str.c_str());
#endif  // DEBUG
}
void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  dht.begin();
  lcd.begin(16,2); 
  lcd.backlight(); 
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.clear();
  lcd.print(" ADJ CONST LOAD");
  delay(2000);
  screenUtama();
  lcd.setCursor(0, 0);
  lcd.write((uint8_t)0);

}

void loop() {
  // put your main code here, to run repeatedly:
}