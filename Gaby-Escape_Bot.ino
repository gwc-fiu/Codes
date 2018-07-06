#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                           // Declare right servo signal
int leftWhisker = 5;
int rightWhisker = 7;
int aValue = digitalRead(leftWhisker);
int bValue = digitalRead(rightWhisker); 

void turnLeft(){
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(800); 
}
void turnRight(){
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(800); 
}
void backwards(){
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(800);                               // ...for 2 seconds
}
void stopbot(){
  servoLeft.writeMicroseconds(1500);        
  servoRight.writeMicroseconds(1500);
  delay(800);
}
void forward(){
  servoLeft.writeMicroseconds(1700);        
  servoRight.writeMicroseconds(1300);
  delay(1000); 
}

void setup(){
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(leftWhisker, INPUT);
pinMode(rightWhisker, INPUT);
servoLeft.attach(13);                      // Attach left signal to pin 13
servoRight.attach(12);                     // Attach right signal to pin 12
servoLeft.writeMicroseconds(1500);        // Calibrate left servo
servoRight.writeMicroseconds(1500);       // Calibrate right servo
}

void loop() {
  // put your main code here, to run repeatedly:\

int aValue = digitalRead(leftWhisker);
int bValue = digitalRead(rightWhisker);
Serial.print("left is:");
Serial.print(aValue); 
Serial.print("right is:");
Serial.print(bValue);
Serial.print("");
if (aValue == 0 && bValue == 0){
  backwards(); 
  turnRight();
}
else if (aValue==0){
  stopbot();
  backwards();
  turnRight();
  forward();
}
else if (bValue==0){
  stopbot();
  backwards();
  turnLeft();
  forward();
}
else{
  forward();
}
delay(100);
}

