#include <DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup()
{
  Serial.begin(115200);
  Serial.print("DHT11 test!");

  dht.begin();
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
  delay(2000);
}