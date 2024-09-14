# include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//DHT
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
//pins
int eco=7;
int trig=8;
int gas_p=A0;
int Time;
//Global variable
int gas;
float Dis,temp,hemo;
//functions
void read_gas();
void read_Dis();
void read_DHT();

void setup() 
{
  Serial.begin(9600);
  dht.begin();

  pinMode(eco, INPUT);
  pinMode(trig, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("Not Working");
    for(;;);
  }
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Bluetooth Module Initialized");
}

void loop() 
{
  read_DHT();
  read_Dis();
  read_gas();

  display.display(); // Show splash screen
  display.clearDisplay(); // Clear the display
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello");

  display.print("Temperature: ");
  display.print(temp);
  display.println(" *C");
  display.print("Humidity: ");
  display.println(hemo);
  display.print("Distance: ");
  display.println(Dis);
  display.print("AQI: ");
  display.println(gas);
  display.display();
  delay(5000);
}

//Functions Definitions
void read_Dis()
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
void read_DHT()
{
  hemo=dht.readHumidity();
  temp=dht.readTemperature();
  if(isnan(hemo) || isnan(temp))
  {
    Serial.println("Failed to read from DHT Sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.println(hemo);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" *c");
}
void read_gas()
{
  gas=analogRead(gas_p);
  Serial.print("Gas sensor reading: ");
  Serial.println(gas);
}