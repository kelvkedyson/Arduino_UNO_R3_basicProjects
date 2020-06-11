int latchPin = 11;
int dataPin = 12;
int clockPin = 9;

byte leds = 0;

void updateShiftRegister(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  updateShiftRegister();
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Enter number 0 to 7 or x to clear");
}

void loop(){
  if(Serial.available()){
    
    char ch = Serial.read();
    if(ch >= '0' && ch <= '7'){
      int led = ch - '0';
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Turned ON LED ");
      Serial.println(led);
    }if(ch == 'x' || ch == 'X'){
      leds = 0;
      updateShiftRegister();
      Serial.println("Cleared");
    }
  }
}
