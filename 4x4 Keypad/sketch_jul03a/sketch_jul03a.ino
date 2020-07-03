/*
   Project name: 4x4 Keypad
   Written by: Kelvin Kedyson Zacharia (BSc.TE-UDSM)
   Date: 3rd July 2020 Friday
*/

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
}

void loop(){
  char customKey = customKeyPad.getKey();
  
  if(customKey){
    Serial.println(customKey);
  }
}
