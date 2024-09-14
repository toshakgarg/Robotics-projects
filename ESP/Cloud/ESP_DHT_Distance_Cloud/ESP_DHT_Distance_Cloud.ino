#include "ESP8266WiFi.h" //Wifi file
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Connectivity variables 
String apiKey = "API_KEY"; //API key from ThingSpeak
const char* server = "api.thingspeak.com";//Server address
const char* ssid = "SSID"; //router's username
const char* password = "PASSWORD"; //router's password
WiFiClient client;

//DHT Variables
#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Ultrasonic pins Location 
int eco=D5;
int trig=D2;

void setup()
{
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  //Condition for Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("Not Working");
    for(;;);
  }
  display.display();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Connecting to WiFi");
  display.display();

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) 
  {//print "." till WiFi connected
    delay(500);
    display.display();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(".");
    display.display();

    Serial.print(".");
  }
  display.display();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("WiFi connected");
  display.println(WiFi.localIP());
  display.display();

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  pinMode(eco, INPUT);
  pinMode(trig, OUTPUT);
}

void loop()
{
  //Distance
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  int Time;
  Time=pulseIn(eco,HIGH);
  float Dis=(Time*0.0343)/2;
  //DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //Connectivity condition
  if (client.connect(server,80))
  {
    String postStr = apiKey;
    postStr +="&field1=";
    postStr += String(t);
    postStr +="&field2=";
    postStr += String(h);
    postStr +="&field2=";
    postStr += String(Dis);
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

    Serial.print("Humidity: ");
    Serial.println(h);
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
    Serial.print("Distance: ");
    Serial.println(Dis);
    Serial.println(" Send to Thingspeak.");

    display.display();
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Humidity: ");
    display.println(h);
    display.print("Temperature: ");
    display.print(t);
    display.println(" *C");
    display.print("Distance: ");
    display.println(Dis);
    display.display();
  }
  client.stop();
  Serial.println("Waiting...");
  delay(1000);
}