/* 
  ProjectName: Controlling 8 LEDS with a photoresistor using 74HC595
  
  Written by: Kelvin Kedyson Zacharia (BSc. TE - UDSM)
  Date : 14th June 2020, Sunday
*/

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int lightPin = 0;

int leds = 0;

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void updateShiftRegister(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void loop(){
  int reading = analogRead(lightPin);
  int numLEDSLit = reading / 57;
  
  if(numLEDSLit > 8) numLEDSLit = 8;
  leds = 0;
  for(int i = 0; i < numLEDSLit; i++){
    leds = leds + (1 << i);
  }
  updateShiftRegister();
}


