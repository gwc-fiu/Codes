// Robotics with the BOE Shield - ForwardThreeSeconds
// Make the BOE Shield-Bot roll forward for three seconds, then stop.

#include <Servo.h>                           // Include servo library
 
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;

void Stringback(){
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(1000); 
}

void Stringfront(){
  servoLeft.writeMicroseconds(1300);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel clockwise
  delay(1000); 
}

void Stringbacks(){
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(500); 
}

void Stringfronts(){
  servoLeft.writeMicroseconds(1300);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel clockwise
  delay(500); 
}

void Stringswirl(){
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel clockwise
  delay(1700); 
}

void blink (){
  digitalWrite(8,HIGH);
  delay(1200);
  digitalWrite(8,LOW);
  delay(500);
 
}
void setup()                                 // Built-in initialization block


{  tone(3, 440,1000);                       // Play tone for 1 second
  delay(1000);                               // Delay to finish tone
  tone(3, 430,1000);                       // Play tone for 1 second
  delay(1000);  
  tone(3, 420,1000);                       // Play tone for 1 second
  delay(1000);      
  tone(3, 350,1000);                       // Play tone for 1 second
  delay(1000);          
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12

  // Full speed forward
  Stringback();
  blink(); 
  Stringfront();
  blink(); 
  Stringswirl();
  blink(); 
  Stringfront();
  blink(); 
  Stringback();
  blink(); 
  Stringswirl();
  blink(); 
  Stringbacks();
  blink(); 
  Stringfronts();
  blink(); 
  Stringbacks();
  blink(); 
  Stringfronts();
  blink(); 
  Stringbacks();
  blink(); 
  Stringfronts();
  blink(); 
  Stringswirl();
  Stringfront();
  Stringbacks();
  servoLeft.detach();                        // Stop sending servo signals
  servoRight.detach();

}
 
 
void loop()  // Main loop auto-repeats
{    blink(); 
  // Empty, nothing needs repeating
}
