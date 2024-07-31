#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  
  Serial.print("DHT11 test!");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("Not Working");
    for(;;);  
  }
}

void loop()
{
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  if(isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT Sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *c");

  display.display();
    display.clearDisplay(); 
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("TEMP: ");
    display.println(t);
    display.print("humidity: ");
    display.println(h);
  display.display();

  delay(2000);
}