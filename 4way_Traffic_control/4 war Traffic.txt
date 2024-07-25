int r1=13,r2=10,r3=7,r4=4;
int y1=12,y2=9,y3=6,y4=3;
int g1=11,g2=8,g3=5,g4=2;
void setup()
{
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(y4, OUTPUT);
  pinMode(g4, OUTPUT);
}

void loop()
{
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  
  //for 1sr
  digitalWrite(r1, LOW);
  digitalWrite(y1, HIGH);
  delay(5000);
  digitalWrite(y1, LOW);
  digitalWrite(g1, HIGH);
  delay(10000);
  digitalWrite(g1, LOW);
  digitalWrite(r1, HIGH);
  //for 2nd
  digitalWrite(r2, LOW);
  digitalWrite(y2, HIGH);
  delay(5000);
  digitalWrite(y2, LOW);
  digitalWrite(g2, HIGH);
  delay(10000);
  digitalWrite(g2, LOW);
  digitalWrite(r2, HIGH);
  //for 3rd
  digitalWrite(r3, LOW);
  digitalWrite(y3, HIGH);
  delay(5000);
  digitalWrite(y3, LOW);
  digitalWrite(g3, HIGH);
  delay(10000);
  digitalWrite(g3, LOW);
  digitalWrite(r3, HIGH);
  //for 4th
  digitalWrite(r4, LOW);
  digitalWrite(y4, HIGH);
  delay(5000);
  digitalWrite(y4, LOW);
  digitalWrite(g4, HIGH);
  delay(10000);
  digitalWrite(g4, LOW);
  digitalWrite(r4, HIGH);
}