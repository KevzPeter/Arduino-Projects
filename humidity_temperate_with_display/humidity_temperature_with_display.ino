#include "DHT.h"
#define DHTPIN 4 // you  can use
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    dht.begin();
    lcd.backlight();
    lcd.init();
    Serial.begin(9600);
}
void loop()
{
    lcd.clear();
    lcd.setCursor(0, 0); //  set the cursor on the first row and column
    lcd.print("Humidity ");
    lcd.print((float)dht.readHumidity(), 0); // print  the humidity
    Serial.println((float)dht.readHumidity(), 0);
    lcd.print("%");
    lcd.setCursor(0, 1); // set the cursor on  the second row and first column
    lcd.print("Temperature ");
    lcd.print((float)dht.readTemperature(), 0); // print  the temperature
    Serial.println((float)dht.readTemperature(), 0);
    lcd.print("\xDF");
    lcd.print("C");
    delay(2000);
    lcd.clear();
}