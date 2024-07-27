#include "ESP8266WiFi.h"
# include <DHT.h>
#include<MQ135.h>

#define DHTPIN D6
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
MQ135 gasSensor = MQ135(A0);

String apiKey = "VHBY3WBJ0K5YTB2R"; // Enter your Write API key from ThingSpeak
const char* server = "api.thingspeak.com";
// WiFi parameters to be configured
const char* ssid = "vivo T1 5G"; // Write here your router's username
const char* password = "anand921"; // Write here your router's password

int eco=D5;
int trig=D2;

WiFiClient client;
void setup()
{
  Serial.begin(115200);
  pinMode(eco, INPUT);
  pinMode(trig, OUTPUT);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP()); // Print the IP address
}

void loop()
{
  //ULTRASONIC
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  int Time;
  Time=pulseIn(eco,HIGH);
  float Dis=(Time*0.0343)/2;
  Serial.print("Distance: ");
  Serial.println(Dis);
  
  //DHT
  float humi=dht.readHumidity();
  float temp=dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.println(humi);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" *c");
  
  //GAS snsor
  float air_quality = gasSensor.getPPM();
  Serial.print("Air Quality: ");
  Serial.println(air_quality);
  
  //conditions
  //condition for DHT
  if(isnan(humi) || isnan(temp))
  {
    Serial.println("Failed to read from DHT Sensor!");
    return;
  }
  //condition to upload
  if (client.connect(server,80))
  {
    String postStr = apiKey;
    postStr +="&field1=";
    postStr += String(temp);
    postStr +="&field2=";
    postStr += String(humi);
    postStr +="&field3=";
    postStr += String(Dis);
    postStr +="&field4=";
    postStr += String(air_quality);
    postStr += "\r\n\r\n";
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    Serial.println(" Send to Thingspeak.");
  }
  client.stop();
  Serial.println("Waiting...");
  delay(5000);
}