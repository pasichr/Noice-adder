#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>



//jamming the 2.4GHz band using UWB noise <random>

RF24 radio(9,10);  //CE , CSN    #previous 7,8
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(){

  //pinMode(2, OUTPUT);
  radio.begin();
  radio.setChannel(76); //2.4GHz 
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.setRetries(15,15);
  radio.openWritingPipe(pipe);
}

void loop(){

  // add led blink when jammer on
   //jamming code 
  uint8_t data[32];
  for (int i=0;i<32;i++){
    data[i]=random(0,255);
  }
  radio.write(data,32);
  delay(1);

   //digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level)
   //delay(50); // wait for a second
   //digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
   //delay(50); // wait for a second
}
