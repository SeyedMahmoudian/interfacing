int latchPin = 8;
int dataPin = 11;
int clockPin = 12;
int dato = 0;
int waitFor = 100;

int first = 0;
int second = 0;

void setup() {
  pinMode (dataPin, OUTPUT);
  pinMode (clockPin, OUTPUT);
  pinMode (latchPin, OUTPUT);
}

void loop() {
  /*first 8 led*/
  lightLeds (0b00000000, 0b00000000);//0
  delay(waitFor);
  lightLeds (0b00000000, 0b00000001);//1
  lightLeds (0b00000000, 0b00000011);//2
  lightLeds (0b00000000, 0b00000111);//3
  lightLeds (0b00000000, 0b00001111);//4
  lightLeds (0b00000000, 0b00011111);//5
  lightLeds (0b00000000, 0b00111111);//6
  lightLeds (0b00000000, 0b01111111);//7
  lightLeds (0b00000000, 0b11111111);//8
  /*second 8 led*/
  lightLeds (0b00000001, 0b11111111);//0
  lightLeds (0b00000011, 0b11111111);//1
  lightLeds (0b00000111, 0b11111111);//2
  lightLeds (0b00001111, 0b11111111);//3
  lightLeds (0b00011111, 0b11111111);//4
  lightLeds (0b00111111, 0b11111111);//5
  lightLeds (0b11111111, 0b11111111);//6
  //lightLeds (0b00000000, 0b00000000);//7
  delay(waitFor);
  /*second 8 led backward*/
  lightLeds (0b01111111, 0b11111111);//0
  lightLeds (0b00111111, 0b11111111);//1
  lightLeds (0b00011111, 0b11111111);//2
  lightLeds (0b00011111, 0b11111111);//3
  lightLeds (0b00001111, 0b11111111);//4
  lightLeds (0b00000111, 0b11111111);//5
  lightLeds (0b00000011, 0b11111111);//6
  lightLeds (0b00000001, 0b11111111);//7
  lightLeds (0b00000000, 0b11111111);//8
  /*first 8 led backward*/
  lightLeds (0b00000000, 0b01111111);//0
  lightLeds (0b00000000, 0b00111111);//1
  lightLeds (0b00000000, 0b00011111);//2
  lightLeds (0b00000000, 0b00001111);//3
  lightLeds (0b00000000, 0b00000111);//4
 lightLeds (0b00000000, 0b00000111);//4
 lightLeds (0b00000000, 0b00000011);//5
 lightLeds (0b00000000, 0b00000001);//6
  lightLeds (0b00000000, 0b00000000);//7
  delay(waitFor);
}

void lightLeds (byte second, byte first) {
  digitalWrite (latchPin, LOW);
  shiftOut (dataPin, clockPin, LSBFIRST, first);
  shiftOut (dataPin, clockPin, LSBFIRST, second);
  digitalWrite (latchPin, HIGH);
  delay (waitFor);

}
