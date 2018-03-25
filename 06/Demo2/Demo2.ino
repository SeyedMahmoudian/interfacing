int RCLK = 8;
int SRCLK = 12;
int SER = 11;
byte data;
byte dataArray[8];

void setup() {
  pinMode(RCLK, OUTPUT);
  dataArray[0] = 0x01; //0000 0001
  dataArray[1] = 0x02; ////0000 0010
  dataArray[2] = 0x04; //0000 0100
  dataArray[3] = 0x08; //0000 1000
  dataArray[4] = 0x10;//0001 0000
  dataArray[5] = 0x20; //0010 0000
  dataArray[6] = 0x40; //0100 0000
  dataArray[7] = 0x80; //1000 0000
}

void loop() {

  for (int j = 0; j < 8; j++) {
    data = dataArray[j];
    digitalWrite(RCLK, 0);
    shiftOut(SER, SRCLK, data);
    
    digitalWrite(RCLK, 1);
    delay(100);
  }
  for (int i = 8 ; i > 0; i--) {
    data = dataArray[i];
    digitalWrite(RCLK, 0);
    shiftOut(SER, SRCLK, data);

    digitalWrite(RCLK, 1);
    delay(100);
  }
}
void shiftOut(int mySER, int mySRCLK, byte myDataOut) {
  int i = 0;
  int pinState;
  pinMode(mySRCLK, OUTPUT);
  pinMode(mySER, OUTPUT);
  digitalWrite(mySER, 0);
  digitalWrite(mySRCLK, 0);

  for (i = 7; i >= 0; i--)  {
    digitalWrite(mySRCLK, 0);

    if ( myDataOut & (1 << i) ) {
      pinState = 1;
    }
    else {
      pinState = 0;
    }

    digitalWrite(mySER, pinState);
    digitalWrite(mySRCLK, 1);
    digitalWrite(mySER, 0);
  }

  digitalWrite(mySRCLK, 0);

}
