#include <SoftwareSerial.h>

// Define RX and TX pins for Bluetooth
SoftwareSerial bluetooth(12, 13);  // RX, TX

void setup() {
  // Start serial communication for the Serial Monitor
  Serial.begin(9600);

  // Start the Bluetooth serial communication
  bluetooth.begin(9600);  // Make sure the baud rate matches your Bluetooth module
}

void loop() {
  // Check if there's any data coming from the Bluetooth module
  if (bluetooth.available()) {
    // Read the incoming data
    char incomingData = bluetooth.read();

    // Print the data to the Serial Monitor
    Serial.print("Received: ");
    Serial.println(incomingData);
  }
}
