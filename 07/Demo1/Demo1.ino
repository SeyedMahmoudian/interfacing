int val=0;
const byte ledCharSet[10] =
{
  //abcdefgp
  0b00000010, // 0
  0b10011110, // 1
  0b00100100, // 2
  0b00001100, // 3
  0b10011000, // 4
  0b01001000, // 5
  0b01000000, // 6
  0b00011110, // 7
  0b00000000, // 8
  0b00011000//9
};

const int latchPin=8;
const int clockPin=12;
const int dataPin=11;
const int voltmeter=15;
void setup() {
  pinMode(voltmeter,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 val=analogRead(voltmeter);
 float voltage = val * (3.3/1023.0);  
 int first = (int)voltage;
 int test = (voltage-first)*10;
 Serial.println(voltage);
 digitalWrite(latchPin,0);
 Serial.println("printing first:");
 Serial.println(first);
 shiftOut(dataPin,clockPin,LSBFIRST,ledCharSet[test]);
 digitalWrite(latchPin,1);
 digitalWrite(latchPin,0);
 Serial.println("printing test");
  Serial.println(test);
 shiftOut(dataPin,clockPin,LSBFIRST,ledCharSet[first]);
 digitalWrite(latchPin,1);
 delay(500);
 Serial.println("-----");
 
 
 
}
