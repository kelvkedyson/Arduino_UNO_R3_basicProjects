const int tiltPin = 2;
const int ledPin = 3;

int tiltState = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(tiltPin, INPUT);
}

void loop(){
  tiltState = digitalRead(tiltPin);
  
  if(tiltState == HIGH){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}
