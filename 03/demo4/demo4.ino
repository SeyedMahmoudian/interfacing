const int green = 2;
const int blue = 3;
const int red = 4;
const int BUTTON = 14;
int counter = 0;
int val = 0;
int btnpressed = 0;
void setup()
{
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(BUTTON, INPUT);
}
void loop()
{
  val = digitalRead(BUTTON);
  if (val == 1 && btnpressed == 0) {

    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    delay(100);

  } else {
    btnpressed = 1;
    if (val == 0) {
      if (counter == 3) {
        counter = 1;
      } else {
        counter++;
      }
    }
    if (counter == 1) {
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(green, HIGH);
      delay(250);
    }
    if (counter == 2) {
      digitalWrite(blue, LOW);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      delay(250);
    }
    if (counter == 3) {
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
      digitalWrite(blue, HIGH);
      delay(250);

    }


  }
}



