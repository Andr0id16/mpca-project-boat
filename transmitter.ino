#include <SPI.h>
#include "RF24.h" 
RF24 radio(9,10);
const uint64_t pipe = 0xF0F0F0F000LL; 
int msg[1]; 
int potpin_1 = A0; 
int val_1; 
int potpin_2 = A1; 
int val_2; 

void setup(void){
radio.begin();
radio.openWritingPipe(pipe); 

}
void loop() {
val_1 = analogRead(potpin_1),val_1 = map(val_1, 0, 1023, 0, 127),msg[0] = val_1,radio.write(msg, 1);
val_2 = analogRead(potpin_2),val_2 = map(val_2, 0, 1023, 128, 255),msg[0] = val_2,radio.write(msg, 1);

}

