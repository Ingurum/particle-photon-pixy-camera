
//pixy-d7.ino

// By Jeremy Ellis

// Note: Watch the RGB LED at startup.
// If it quickly goes to breathing cyan, you have Wifi connectivity
// If it takes 20 seconds to go to breathing cyan, then you have no Wifi connectivity but the Pixy should still work


///      #include "SPI.h"        // got rid of this since it would not compile
#include "Pixy.h"
#include "TPixy.h"

Pixy pixy;                          // Create our pixy object

void setup() {   
    pinMode(D7, OUTPUT); 
    
    RGB.brightness(25);    // 1=very low light, 255 = max
    pixy.init();                    // Initalize the pixy object
}


void loop(){ 
    
    uint16_t    blocks;                       // Create an unsigned int to hold the number of found blocks
    char        buf[50];                      // Create a buffer for printing over serial
    int         myPixyInt;

    blocks = pixy.getBlocks();      // Do the pixy stuff. Grab the numbers of blocks the pixy finds
  

  if (blocks) {

    myPixyInt = pixy.blocks[0].width;    // width of detected largest object    0 - 320
   // myPixyInt = pixy.blocks[0].x;    
   // myPixyInt = pixy.blocks[0].y;
   // myPixyInt = pixy.blocks[0].width;
   // myPixyInt = pixy.blocks[0].height;
   

   if (myPixyInt <= 10) {   
       digitalWrite(D7, LOW);     // Object very small or far away D7 LED off
    }  
    
    if (myPixyInt > 10 && myPixyInt <= 30) {    // Object far away, blink really fast
        digitalWrite(D7, HIGH);                  
        delay(5);                                          
        digitalWrite(D7, LOW); 
        delay(5);
    }  
 
    if (myPixyInt > 30 && myPixyInt <= 100) {    // Object close, blink slow
        digitalWrite(D7, HIGH);                  
        delay(500);                                          
        digitalWrite(D7, LOW); 
        delay(500);
    }  
      
    if (myPixyInt > 100 && myPixyInt <= 300) {    // Object close, blink really slow
        digitalWrite(D7, HIGH);                  
        delay(1000);                                          
        digitalWrite(D7, LOW); 
        delay(1000);
    }  
 
    if (myPixyInt > 300 ) {    // Object very close, leave LED on
        digitalWrite(D7, HIGH);                  
    }  

   delay(5); // just for the heck of it to slow things down a bit
  } // end blocks
}   // end loop













