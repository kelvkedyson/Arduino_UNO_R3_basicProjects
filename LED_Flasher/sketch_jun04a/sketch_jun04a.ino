int ledPin = 10;

//code to setup the program, this code runs only once.
void setup(){
  pinMode(ledPin, OUTPUT);
}

// this code runs more than once
void loop(){
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(700);
}
