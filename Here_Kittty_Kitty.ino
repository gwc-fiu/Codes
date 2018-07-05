#include <Servo.h>                           // Include servo library

Servo servoRight;
Servo servoLeft;

int leftWhisker = 5;
int rightWhisker = 7;

 void back() {
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(1500);
}

 void front() {
 servoLeft.writeMicroseconds(1300);
 servoRight.writeMicroseconds(1700);
 delay(1500);
 }
 
 void left() {
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(1500);
 }

void right() {
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(1500);
}




void moveKitty() {
  // Your Code Here
  
  
}

void stopKitty() {
  // Your Code Here
   servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1500);
}

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);
  servoRight.attach(12);
//  front();
//  delay(1500);
//  back();
//  delay(1500);
//  right();
//  delay(1500);
//  left();
//  delay(1500);

  
  Serial.begin(9600);
  Serial.println("setup completed");
  pinMode(leftWhisker, INPUT);
  pinMode(rightWhisker, INPUT);
}
  //Your Code Here


void loop() {
  // put your main code here, to run repeatedly:
   // put your main code here, to run repeatedly:
      front();
   int aValue = digitalRead(leftWhisker);
   int bValue = digitalRead(rightWhisker);
   if(aValue == 0 && bValue == 1) {
      Serial.println("Left Pressed!");
      stopKitty();
      back();
      left();
      front();
   }
   else if(bValue == 0 && aValue == 1) {
     Serial.println("Right Pressed!");
      stopKitty();
      back();
      right();
      front();
  // }else if(aValue == 0 && bValue == 0) {
     //Serial.println("Both Pressed!");
      //stopKitty();
      //back();
      //right();
      //front(); 
      }
  //delay(100); 
  }
  //Your Code Here

