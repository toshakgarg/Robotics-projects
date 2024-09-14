
#include <Servo.h>

Servo servo_2;
int servo =D2;
void setup()
{
  servo_2.attach(servo, 500, 2500);
}

void loop()
{
  servo_2.write(90);
  delay(5000); // Wait for 5000 millisecond(s)
  servo_2.write(0);
  delay(1000); // Wait for 1000 millisecond(s)
}