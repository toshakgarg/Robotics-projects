#include <Servo.h>
Servo servo_2;
int servo =3;

int eco=8;
int trig=9;
int buzz=12;
void setup()
{
  Serial.begin(9600);
  pinMode(eco, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzz,OUTPUT);
  servo_2.attach(servo, 500, 2500);
}

void loop()
{
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  int Time;
  Time=pulseIn(eco,HIGH);
  float Dis=(Time*0.0343)/2;

  if(Dis<15)
  {
    digitalWrite(buzz,HIGH);
    servo_2.write(90);
  }
  else
  {
    digitalWrite(buzz,LOW);
    servo_2.write(0);
  }

}