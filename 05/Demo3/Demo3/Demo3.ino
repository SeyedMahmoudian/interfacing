const int e = 3;
const int d = 4;
const int c = 5;
const int dp = 6;
const int b = 18;
const int a = 19;
const int f = 20;
const int g = 21;
const int fPin = 11;
const int sPin = 14;

const int lights[10][8] = {
  //a,b, c, d, e, f, g, p
  {0, 0, 0, 0, 0, 0, 1, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0, 1}, // 2
  {0, 0, 0, 0, 1, 1, 0, 1}, // 3
  {1, 0, 0, 1, 1, 0, 0, 1}, // 4
  {0, 1, 0, 0, 1, 0, 0, 1}, // 5
  {0, 1, 0, 0, 0, 0, 0, 1}, // 6
  {0, 0, 0, 1, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0, 1}, // 8
  {0, 0, 0, 1, 1, 0, 0, 1} // 9

};
const int pins[7] = {a, b, c, d, e, f, g};
//const int pins[7]={e,d,c,b,a,f,g};
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(11, OUTPUT); //driver pins.
  pinMode(14, OUTPUT); //driver pins.

}

void loop() {
  digitalWrite(fPin, HIGH);
  digitalWrite(sPin, HIGH);

  for (byte i = 0; i <= 9; i++) {
  
    for (byte j = 0 ; j <= 8; j++) {
      digitalWrite(pins[i], lights[i][j]);
    //  delay(500);
    
      digitalWrite(pins[j], lights[i][j]);
    }

  }

}
