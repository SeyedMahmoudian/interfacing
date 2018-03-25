#define interrupt_C 15
#define interrupt_D  16
#define interrupt_E  17
#define interrupt_F  18
#define speaker  10
//int interrupt_C_State  0
//int interrupt_D_State = 0;
//int interrupt_E_State = 0;
//int interrupt_F_State = 0;
int tones[] = {4186, 951, 880, 3322}; //freq
int Cur_tone = 0;
void setup() {
  pinMode(interrupt_C, INPUT);
  pinMode(interrupt_D, INPUT);
  pinMode(interrupt_E, INPUT);
  pinMode(interrupt_F, INPUT);
  pinMode(speaker, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(interrupt_C), buttonC, HIGH);

  attachInterrupt(digitalPinToInterrupt(interrupt_D), buttonD, HIGH);

  attachInterrupt(digitalPinToInterrupt(interrupt_E), buttonE, HIGH);

  attachInterrupt(digitalPinToInterrupt(interrupt_F), buttonF, HIGH);

  Serial.begin(9600);
}
void buttonC() {
  Serial.println("BUttonC");
  Cur_tone = tones[0];
  sounds(Cur_tone);

}
void buttonD() {
  Serial.println("BUttonD");
  Cur_tone = tones[1];
  sounds(Cur_tone);
 
}
void buttonE() {
  Serial.println("BUttonE");
  Cur_tone = tones[2];
  sounds(Cur_tone);

}
void buttonF() {
  Serial.println("BUttonF");
  Cur_tone = tones[3];
  sounds(Cur_tone);
 
}
void sounds(int i) {
  digitalWrite(speaker, HIGH);
  delayMicroseconds(i);
  digitalWrite(speaker, LOW);
  delayMicroseconds(i);
//  digitalWrite(speaker, LOW);
  
}

void loop() {
}
