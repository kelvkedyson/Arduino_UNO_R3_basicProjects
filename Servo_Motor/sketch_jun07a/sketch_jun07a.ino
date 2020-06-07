//including the servo library
#include <Servo.h>

//declaring the servo signal pin
int servoPin = 9;

//creating a servo object
Servo servo;

void setup(){
  //attaching the servo object to servoPin
  servo.attach(servoPin);
}

void loop(){
  
  //argument passed is an angle in degrees measure of which the servo will rotate
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1000);
  
}
