
int minReading = 65536;
int maxReading = 0;

void setup()   {
  Serial.begin(9600);
 
  pinMode(11, OUTPUT);
  pinMode(A1,INPUT);
  pinMode(13, OUTPUT);
  
  calibrate();
   delay(500);
}


void loop()
{
    calibrate();

}
void calibrate() {
  //Serial.println("ENTERED");
  int reading;
  for (int i = 0; i < 100; i++)
  {
    reading = touchRead(A1);

    if (reading < minReading)
      minReading = reading;

    if (reading > maxReading)
      maxReading = reading;
  }
  int secondVal=f(A3);
  Serial.println("Max Reading:");
  Serial.println(maxReading);
  Serial.println("Min Reading:");
  Serial.println(minReading);
  Serial.println("Sensor");
  Serial.println(secondVal);
  tone(10,reading);
  delay(400);
  tone(10,secondVal);
} //end calibrate
