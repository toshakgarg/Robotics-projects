void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int g=analogRead(A0);
  Serial.println(g);
  delay(1000);
}