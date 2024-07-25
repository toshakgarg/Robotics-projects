int LDR=A0;
int LED=7;
void setup()
{
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int data=analogRead(LDR);
  Serial.print("Data ");
  Serial.println(data);
  if(data<50)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
    digitalWrite(LED,HIGH);
  }
  delay(1000);
}