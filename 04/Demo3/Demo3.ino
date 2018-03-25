#include <Bounce.h>

void setup() {

  Keyboard.begin();
  emailToText();

  Keyboard.end();

}

void emailToText() {
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  delay(1000);
  Keyboard.press(KEY_M);
  Keyboard.releaseAll();
  delay(10000);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  delay(40);
  Keyboard.press(KEY_N);
  delay(40);
  Keyboard.releaseAll();
  Keyboard.println("6137006802@txt.freedommobile.ca");
  Keyboard.releaseAll();
  delay(200);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(2000);
  /*Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(2000);*/
  Keyboard.println("Sending automated text");
  Keyboard.releaseAll();
  delay(200);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(40);
  Keyboard.println("if you see this so far so good");
  Keyboard.releaseAll();
  delay(400);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  // delay(1000);
  delay(40);
 Keyboard.press(KEYPAD_ENTER);
  Keyboard.releaseAll();

}
void loop() {

}

