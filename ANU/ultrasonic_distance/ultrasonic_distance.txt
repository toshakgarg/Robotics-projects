int eco=8;
int trig=9;
int BUZZER=2;
void setup()
{
  Serial.begin(9600);
  pinMode(eco, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(BUZZER,OUTPUT);
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
  Serial.print("Distance: ");
  Serial.println(Dis);
  if(Dis<60)
  {
    digitalWrite(BUZZER,HIGH);
  }
  else
  {
    digitalWrite(BUZZER,LOW);
  }
  delay(100);
}