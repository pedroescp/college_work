#include "Servo.h"

Servo servo1;
Servo servo2;


void setup() {
  //take the Servo por 5 
  servo1.attach(5);
  servo2.attach(2);
}

void loop() {
  
  //read a value of potenciometro
  int angle = analogRead(0);
  int angle1 = analogRead(1);
  
  //Map the value 0 to 180 
  angle=map(angle, 0, 1024, 0, 180);
  angle1=map(angle1, 0, 1024, 0, 180);
  
  //pass the angulo to ServoWrtite
  servo1.write(angle);
  servo2.write(angle1);

  //delay to rotate the servo
  delay(15);
}
