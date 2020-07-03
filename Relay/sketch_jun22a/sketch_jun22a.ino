/* 
    Project Name: Relay
    Written by: Kelvin Kedyson Zacharia
    Date: 22nd June 2020, Monday
*/

#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;


void setup(){
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println("One way, then reverse");
  digitalWrite(ENABLE, HIGH);
  for(i = 0; i < 5; i++){
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    delay(750);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
    delay(750);
  }
  digitalWrite(ENABLE, LOW);
  delay(3000);
  for(i = 0; i < 5; i++){
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    delay(750);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
    delay(750);
  }
  digitalWrite(ENABLE, LOW);
  delay(3000);
}
