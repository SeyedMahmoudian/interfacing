
#include <Bounce.h>
const int screenX = 1440;
const int screenY = 900;
void setup() {

  Mouse.begin();
  Mouse.screenSize(screenX, screenY, true);
  Keyboard.begin();
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  delay(1000);
  Keyboard.press(KEY_P);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_ENTER);
  delay(100);
  Keyboard.release(KEY_ENTER);
  Mouse.move(screenX % 2, screenY % 2);
  delay(1000);
  delay(40);
  drawCir();
  delay(40);
  drawCube();
  delay(40);
  drawDiamond();
  delay(40);
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  delay(40);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  delay(40);
  Keyboard.press(KEY_S);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.println("SelfAwarePicture");
  delay(1000);
  Keyboard.releaseAll();
  Keyboard.end();

}
void drawCir() {
  int x=0 , y=0;
  float angle = 0.0;
  float angle_step = 0.1;
  int len = 20;
  Mouse.moveTo(154, 140);
  while (angle < 2 * PI) {
    x = len * cos(angle);
    y = len * sin(angle);
    Mouse.press();
    Mouse.set_buttons(1, 0, 0, 0);
    Mouse.move(x + screenX % 4, y + screenY % 4);
    delay(50);
    angle += angle_step;
  }
  Mouse.release();
}

void drawCube() {
delay(50);
  Mouse.moveTo(454, 140);
  delay(40);
  Mouse.press();
  Mouse.set_buttons(1,0,0,0);
  Mouse.move(50,0);
  delay(40);
  Mouse.move(70,0);
  delay(400);
  Mouse.move(0,70);
  delay(400);
  Mouse.move(-97,0);
  delay(400);
  Mouse.move(0,-70);
  delay(400); 
  Mouse.release();

}
void drawDiamond(){
  Mouse.moveTo(1030,140);
  delay(40);
  Mouse.press();
  Mouse.set_buttons(1,0,0,0);
  Mouse.move(53,40);
  delay(400);
  Mouse.move(-53,40);
  delay(400);
  Mouse.move(-53,-40);
  delay(400);
  Mouse.move(53,-40);
  delay(400);
   Mouse.release();
}
void loop(){
  
}

