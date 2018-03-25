const int VinputPin = 17;
const int otherPin=5;
const int dataPin = 11; //Pin connected to Pin 14 of 74HC595 (Data) 11
const int latchPin = 8; //Pin connected to Pin 12 of 74HC595 (Latch) 8
const int clockPin = 12; //Pin connected to Pin 11 of 74HC595 (Clock) 12
const byte decimalDisplay = 9;

const byte bitPattern[] =
{
  B00000011, // 0
  B10011111, // 1
  B00100101, // 2
  B00001101, // 3
  B10011001, // 4
  B01001001, // 5
  B01000001, // 6
  B00011111, // 7
  B00000001, // 8
  B00001001  // 9
};

void setup() {
  pinMode(VinputPin, INPUT);
  pinMode(otherPin,OUTPUT);
  digitalWrite(otherPin,HIGH);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(decimalDisplay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  byte digitOne;
  byte digitTwo;
  byte mappedVin;
  byte temp;
  byte mappedTemp;
  int potValue;
  int inPutOther;
  potValue = analogRead(VinputPin);
  inPutOther=digitalRead(otherPin);
  Serial.println("pot value");
  Serial.println(potValue);
  Serial.println("otherpin:");
  Serial.println(otherPin);
  mappedVin = map(potValue, 0, 1023, 0, 33);
  Serial.println("mappedVin:");
  Serial.println(mappedVin);
  if (mappedVin <= 10) {
    mappedTemp = map(mappedVin, 0, 10, 0, 99);

    digitTwo = mappedTemp / 10;
    digitTwo = bitPattern[digitTwo];


    digitOne = mappedTemp % 10;
    digitOne = bitPattern[digitOne];


    digitalWrite(decimalDisplay, LOW);

  } else {
    digitalWrite(decimalDisplay, HIGH);

    digitTwo = mappedVin / 10;
    digitTwo = bitPattern[digitTwo] & B11111110;
   Serial.println("digit two");
    Serial.println(digitTwo);
    digitOne = mappedVin % 10;
    digitOne = bitPattern[digitOne];
    Serial.println("digit one");
    Serial.println(digitOne);
  }
  digitalWrite(latchPin, LOW);
  shiftOut(digitOne);
  shiftOut(digitTwo);

  digitalWrite(latchPin, HIGH);
  delay(100);
}

void shiftOut(byte dataOut) {
  boolean pinState;
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  for (int i = 0; i <= 7; i++) {
    digitalWrite(clockPin, LOW);

    if ( dataOut & (1 << i) ) {
      pinState = HIGH;
    }
    else {
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, LOW);
  }
  digitalWrite(clockPin, LOW);
}


