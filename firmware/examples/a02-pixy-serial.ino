
//pixy-serial.ino


// By Jeremy Ellis
// Twitter @rocksetta
// website http://rocksetta.com


///      #include "SPI.h"        // got rid of this since it would not compile
#include "Pixy.h"
#include "TPixy.h"

Pixy pixy;                          // Create our pixy object

void setup() {   
  
    Serial.begin(9600);
    Serial.println("Starting...");
    pixy.init();
   
}


void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  // grab blocks of all objects detected at that moment
  blocks = pixy.getBlocks();
  
  // If blocks, print them!
  if (blocks)
  {
    i++;
    if (i%20==0)
    {
      for (j=0; j < blocks; j++)
      {
        sprintf(buf, "block %d: ", j);
        Serial.print(buf); 
        pixy.blocks[j].print();
        Serial.print("\r");        //cariage return only
      }
      Serial.println();           // print empty line after each set of objects
    }
  }  
}




