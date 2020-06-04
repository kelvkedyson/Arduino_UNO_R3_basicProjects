int redPin = 6;
int greenPin = 5;
int bluePin = 3;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  color(255, 0, 0);
  delay(1000);
  
  color(0, 255, 0);
  delay(1000);
  
  color(0, 0, 255);
  delay(1000);
}

void color(unsigned char red, unsigned char green, unsigned char blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
