int x;  //declare integer variables for x and y analog readings
int y;

void setup() {
  Serial1.begin(9600);                              //initialize xbee serial communication
  attachInterrupt(digitalPinToInterrupt(2), Stop, FALLING);  
  }                                                        //interrupt button for stopping car with a push down of joystick

void loop() {
  x = analogRead(A0);                             //set variables to analog values
  y = analogRead(A1);

// the way it was wired x became y for directing car for easier handling of the joystick
  if(x >= 770){                                                          //reading for forwards
    Serial1.write('f');                                    //send ‘f’ to parallax xbee
    while (analogRead(A0)>= 770) {}        // just send f once
  }
  else if (x <= 255){                 //reading for backwards
    Serial1.write('b');               //send b to xbee
    while(analogRead(A0) <= 255){}    //only send it once
  }
  else if (y >= 770){                      //reading for right
    Serial1.write('r');         //send r to xbee
    while(analogRead(A1) >= 770){}     //only send it once
  }
  else if(y <= 255){                      //reading for left
    Serial1.write('l');        //send l to xbee
    while(analogRead(A1) <= 255){}     //only send it once
  }
}
    
void Stop(){              //function for Stop interrupt call
  delay(250);            //pause 250ms
  Serial1.write('s');  //send s to xbee
}
