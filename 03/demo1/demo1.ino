const int red=3;
const int blue=4;
const int green=5;
void setup() {
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  

}

void loop() {
  digitalWrite(red,HIGH);
  delay(100);
  digitalWrite(red,LOW);
  delay(100);
  digitalWrite(blue,HIGH);
  delay(100);
  digitalWrite(blue,LOW);
  delay(100);
  digitalWrite(green,HIGH);
  delay(100);
  digitalWrite(green,LOW);

}
