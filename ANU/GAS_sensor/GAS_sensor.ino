#include<MQ135.h>
MQ135 gasSensor = MQ135(A0);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float air_quality = gasSensor.getPPM();
  Serial.print("Air Quality: ");
  Serial.println(air_quality);
  delay(1000);
}