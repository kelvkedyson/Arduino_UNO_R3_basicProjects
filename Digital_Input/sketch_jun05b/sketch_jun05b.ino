int ledPin = 5;
int buttonApin = 8;
int buttonBpin = 9;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(buttonApin) == LOW){
    digitalWrite(ledPin, HIGH);
  }
  if(digitalRead(buttonBpin) == LOW){
    digitalWrite(ledPin, LOW);
  }
}
