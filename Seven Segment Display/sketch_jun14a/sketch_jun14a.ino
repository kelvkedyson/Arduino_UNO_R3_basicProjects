/*
  Project Name: 74HC595 and 7 Segment display
  Written by: Kelvin Kedyson Zacharia (BSc.TE - UDSM)
  Date:14th June, 2020 Sunday
*/

byte seven_seg_digits[10] = {
                              B11111100,
                              B01100000,
                              B11011010,
                              B11110010,
                              B01100110,
                              B10110110,
                              B10111110,
                              B11100000,
                              B11111110,
                              B11100110
                           };
                           
int dataPin = 12;
int latchPin = 11;
int clockPin = 9;

void setup(){
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void sevenSegWrite(byte digit){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);
  digitalWrite(latchPin, HIGH);
}

void loop(){
  for(byte digit = 10; digit > 0; --digit){
    delay(1000);
    sevenSegWrite(digit - 1);
  }
  
  delay(3000);
}
