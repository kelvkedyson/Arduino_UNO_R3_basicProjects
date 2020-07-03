/*
  Project Name: Stepper motor 28BYJ-48
  Written by: Kelvin Kedyson Zacharia (BSc.TE-UDSM)
  Date: 3rd July, 2020
*/

#include <Stepper.h>

const int stepsPerRevolution = 1500;

Stepper myStepper(stepsPerRevolution, 8,10,9,11);

void setup(){
  //setting the speed at 30rpm
  myStepper.setSpeed(30);
  Serial.begin(9600);
}

void loop(){
  Serial.println("Clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  
  Serial.println("Counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}



