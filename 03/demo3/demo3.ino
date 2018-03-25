const int green=3;
const int blue=4;
const int red=5;
const int BUTTON =14;
int val=0;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(BUTTON,INPUT);
  
}

void loop() { 
  val=digitalRead(BUTTON);

  if(val==HIGH){
   digitalWrite(green,LOW);
     digitalWrite(red,HIGH);
     delay(100);
     digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
     delay(100);
      digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
     delay(100);
  }else {  
     digitalWrite(red,LOW);
     digitalWrite(blue,LOW);
     digitalWrite(green,LOW);
    
  }
}
