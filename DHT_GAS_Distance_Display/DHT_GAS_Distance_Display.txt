# include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//DHT
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
//pins 
int eco=9;
int trig=10;
int gas_p=A0;
//Global Variable 
float humi,temp,Dis;
int Time,gas;
//function
void temp_humi();//data collected and print on Serial monitor
void gass();//data collected and print on Serial monitor
void ultra();//data collected and print on Serial monitor

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

  display.display(); 
    display.clearDisplay(); 
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Temperature: ");
    display.println(temp);
    display.print("Humidity: ");
    display.println(humi);
    display.print("GAS: ");
    display.println(gas);
    display.print("distance: ");
    display.println(Dis);
  display.display();
  delay(2000);
}

void temp_humi()
{
  humi=dht.readHumidity();
  temp=dht.readTemperature();

  if(isnan(humi) || isnan(temp))
  {
    Serial.println("Failed to read from DHT Sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.println(humi);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" *c");
}

void gass()
{
  gas=analogRead(gas_p);
  Serial.print("Gas sensor reading: ");
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
