#include <Servo.h>
Servo servo_2;

int servo =3;

void setup()
{
  servo_2.attach(servo, 500, 2500);
}

void loop()
{
  servo_2.write(90);
  delay(1000);
  servo_2.write(0);
  delay(1000);
}