/* FOUR DIGITAL SEVEN SEGMENT DISPLAY
    Written by: Kelvin Kedyson Zacharia-BSc.TE(UDSM)
    Date: 19th June 2020, Friday
*/

int latch = 9;
int clock = 10;
int data = 8;

unsigned char table[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d,
                          0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e,
                          0x79, 0x71, 0x00};
void setup(){
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
}

void Display(unsigned char num){
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);
}

void loop(){
  for(int i = 1; i <= 15; i++){
    Display(i);
    delay(1000);
  }
}
