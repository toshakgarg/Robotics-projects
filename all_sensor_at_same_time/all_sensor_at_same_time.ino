//Including Display library
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//Including Dht lobrary
# include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHTPIN 2
#define DHTTYPE DHT11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN,DHTTYPE);

int eco=9;
int trig=10;

float h,t,Dis;
int Time,gas;

void temp_humi();
void gass();
void ultra();
void setup()
{
  Serial.begin(9600);
  
  //ultrasonic
  pinMode(eco, INPUT);
  pinMode(trig, OUTPUT);
   
  dht.begin();
  
}

void loop()
{
  temp_humi();
  gass();
  ultra();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("Not Working");
    for(;;);
  }

  display.display(); // Show splash screen
    display.clearDisplay(); // Clear the display
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Temperature: ");
    display.println(t);
    display.print("Humidity: ");
    display.println(h);
    display.print("GAS: ");
    display.println(gas);
    display.print("distance: ");
    display.println(Dis);
  display.display();
  delay(2000);
}


void temp_humi()
{
  h=dht.readHumidity();
  t=dht.readTemperature();

  if(isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT Sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.println("Temperature: ");
  Serial.println(t);
  Serial.println(" *c");
}

void gass()
{
  gas=analogRead(A0);
  Serial.println(gas);
}

void ultra()
{
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  Time=pulseIn(eco,HIGH);
  Dis=(Time*0.0343)/2;
  Serial.print("Distance: ");
  Serial.println(Dis);
}








