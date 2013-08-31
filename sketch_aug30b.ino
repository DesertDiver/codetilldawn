#include <Esplora.h>

//used to store what we receive
int incomingData = 0;
 
//this function runs only once (after reset)
void setup(){
  //open the serial port and set data rate to 9600 bps
  Serial.begin(9600); 
}
 
//this function runs continuosly (after setup)
void loop(){
   //look if we have data
  if (Serial.available() > 0) {
      //get the sent data
      incomingData = Serial.read();
      Serial.print("We received : ");
      Serial.println(incomingData);
      Serial.print("The LED is : ");
      //49 = ASCII code for '1'
      if (incomingData == 49){ 
        Esplora.writeRGB(255,0,0);
        Serial.println("RED");
      } else {
        Esplora.writeRGB(255,255,0);
        Serial.println("YELLOW");
      }
      Serial.println();
  }
}
