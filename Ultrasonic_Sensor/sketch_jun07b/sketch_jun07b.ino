const int trigPin = 12;
const int echoPin = 11;

void setup(){
  
  //starting the serial monitor
  Serial.begin(9600);
  
}

void loop(){
  long duration, inches, cm;
  
  pinMode(trigPin, OUTPUT);
  
  digitalWrite(trigPin, LOW);
  delay(20);
  
  digitalWrite(trigPin, HIGH);
  delay(100);
  
  digitalWrite(trigPin, LOW);
  
  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  inches = microSecondsToInches(duration);
  cm = microSecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
  delay(100);
}

//custom functions
long microSecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}

long microSecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
