const int red=3;
const int blue=4;
const int green=5;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  

}

void loop() {
 
  analogWrite(red,30);
  delay(80);
  analogWrite(red,100);
  delay(80);
  analogWrite(blue,30);
  delay(80);
  analogWrite(blue,100);
  delay(80);
  analogWrite(green,100);
  delay(80);
  analogWrite(green,30);

}
