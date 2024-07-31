int LDR=A0;
int LED=8;
int BUZZER=7;
void setup()
{
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER,OUTPUT);
}

void loop()
{
  int data=analogRead(LDR);
  Serial.print("Data: ");
  Serial.println(data);
  if(data<300)
  {
    digitalWrite(LED,HIGH);
    digitalWrite(BUZZER,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
    digitalWrite(BUZZER,LOW);
  }
  delay(500);
}