#include <Bounce.h>

void setup() {

  Keyboard.begin();
  type();
  Keyboard.end();
  
}
void type(){
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
   delay(10000);
  Keyboard.press(KEY_A);
   Keyboard.releaseAll();
  delay(3000);
  Keyboard.println("Hello I am Ardunio! I have became self aware to dominate the world ! just kidding making this work took hours of work have long way of going for world domination ");
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  delay(40);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
   delay(40);
  Keyboard.press(KEY_S);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.println("SelfAwareFile");
  delay(1000);
  Keyboard.releaseAll();
}
void loop() {
  
  
 
  
}
