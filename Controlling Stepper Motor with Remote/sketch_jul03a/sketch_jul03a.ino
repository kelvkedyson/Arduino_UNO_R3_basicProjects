/*
  Project Name: Controlling Stepper Motor with Remote
  Written by: Kelvin Kedyson Zacharia (BSc.TE-UDSM)
  Date: 3rd June, 2020 Friday
*/

#include <Stepper.h>
#include <IRremote.h>

const int stepsPerRevolution = 30;
int stepsToTake;
int receiver = 12;

Stepper myStepper(stepsPerRevolution, 8,10,9,11);
IRrecv irrecv(receiver); //this is an instance of irrecv
decode_results results; //this is an instance of decode_results

void setup(){
  irrecv.enableIRIn(); //starting the receiver
  Serial.begin(9600);
}

void loop(){
  //checking if we have received an IR signal
  if(irrecv.decode(&results)){
    switch(results.value){
      case 0xFFA857: //for VOL- btn
        Serial.println("Counterclockwise revolution");
        myStepper.setSpeed(500);
        stepsToTake = 2048; //Rotate clockwisely
        myStepper.step(stepsToTake);
        delay(1000);
        break;
        
       case 0xFF629D: //for VOL+ btn
         Serial.println("Clockwise revolution");
         myStepper.setSpeed(500);
         stepsToTake = -2048;
         myStepper.step(stepsToTake);
         delay(2000);
         break;
    }
    
    irrecv.resume(); //receive the next value
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
  }
}
  
  
  
  
