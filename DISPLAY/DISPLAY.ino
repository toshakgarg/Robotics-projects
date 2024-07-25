#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
      Serial.println("Not Working");
      for(;;);
    } // Address for 128x64 display  
  display.display(); // Show splash screen
  delay(2000);
  display.clearDisplay(); // Clear the display
  display.setTextSize(2.5);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello");
  display.display();

}

void loop() {
  //here we are just try to print one statement,
  // otherwise we will type line 11 to 25 in loop for itteration 
}