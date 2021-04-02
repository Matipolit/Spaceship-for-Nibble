#include <Arduino.h>
#include <CircuitOS.h>
#include <Nibble.h>

Display* display;
Sprite* sprite;

//Assets
#include "assets/sprites.h"
#include "assets/rocket2.h"

//D-pad flags
bool upFlag = false;
bool downFlag = false;
bool leftFlag = false;
bool rightFlag = false;

//Button flags
bool aFlag = false;
bool bFlag = false;
bool cFlag = false;

//Time tracking for timed events
unsigned long previousMillis = 0;
const long interval = 30;

//Colors
uint16_t clrColor = 0;
uint16_t floorColor = 0;
uint16_t wallColor = 0;
uint16_t crateColor = 0;
uint16_t goalColor = 0;
uint16_t playerColor = 0;

//Player coordinates
int playerX = 64;
int playerY = 64;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("Debugging started.");

  SetDisplayColors();

  Nibble.begin();
  display = Nibble.getDisplay();
  sprite = display->getBaseSprite();

  

  RegisterButtonCallbacks();


}

void loop() {
  unsigned long currentMillis = millis();


  Input::getInstance()->loop(0);
  //Serial.println("dupa");
  if (upFlag) {
    Serial.println("up");
  }
  if (downFlag){
      Serial.println("down");
  }
  if (leftFlag){
      Serial.println("left");
  }
  if (rightFlag){
      Serial.println("right");
  }
  //Frame counting
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    //RunScene();
    movePlayer();
    sprite->clear(clrColor);
    sprite->drawIcon(transpRocket, playerX, playerY, 8, 16, 2, 0x0000);

    
    display->commit();
  }


}
