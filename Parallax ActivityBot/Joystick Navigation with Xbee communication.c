#include "simpletools.h"                      // Include simple tools
#include "abdrive360.h"
#include "fdserial.h" 


fdserial *xbee;
int *dataCore;

volatile int data = 's';

void Direction();
 
int main()                                    // Main function
{
  xbee = fdserial_open(9,7,0,9600);
  fdserial_rxFlush(xbee);
  dataCore = cog_run(Direction, 128);
  
 
  while(1){
    data = fdserial_rxChar(xbee);
    pause(1);
  }
}

void Direction(){  
  while(1){
    if(data == 's'){
      drive_speed(0, 0);
    }      
    else if(data == 'f'){
      drive_speed(64, 64);  
    }
    else if(data == 'b'){
      drive_speed(-64, -64); 
    } 
    else if(data == 'r'){
      drive_speed(25, -25);
    }
    else if(data == 'l'){
    drive_speed(-25, 25);
    } 
    pause(200);     
  }
}  