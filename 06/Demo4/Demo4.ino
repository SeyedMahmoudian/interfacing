const byte ledCharSet[10] =
{
  //abcdefgp
  0b00000011, // 0
  0b10011111, // 1
  0b00100101, // 2
  0b00001101, // 3
  0b10011001, // 4
  0b01001001, // 5
  0b01000001, // 6
  0b00011111, // 7
  0b00000001, // 8
  0b00011001
}; // 9

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0 ; j < 10 ; j ++) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, LSBFIRST, ledCharSet[j]);
      digitalWrite(latchPin, 1);
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, LSBFIRST, ledCharSet[i]);
      digitalWrite(latchPin, 1);
      delay(1000);
    }
  }
}

