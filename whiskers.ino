#include <Servo.h>
Servo servoRight;
Servo servoLeft;

int leftWhisker = 5;
int rightWhisker = 7;

void moveKitty() {
  tone(10, 450);
  delay (100);
  tone(10, 750);
  delay (100);
  servoLeft.writeMicroseconds (1700);
  servoRight.writeMicroseconds (1300);
}

void stopKitty() {
  noTone(10);
  servoLeft.writeMicroseconds (1500);
  servoRight.writeMicroseconds (1500);
  delay(500);
  servoLeft.writeMicroseconds (1300);
  servoRight.writeMicroseconds (1700);
  delay (200);
  servoLeft.writeMicroseconds (1300);   // turn
  servoRight.writeMicroseconds (1300);
  delay(1000);
  servoLeft.writeMicroseconds (1500);
  servoRight.writeMicroseconds (1500);
  delay(500);
//  tone (12, 50);
  
}

//for (;;) {
//  tone(10, 450);
//  delay (500);
//  tone(10, 750);
//  delay (500);
//  tone(10, 950);
//  delay (500);
//  if (leftWhiskerValue == 0 || rightWhiskerValue == 0 ) {
//    noTone(12);
//    delay(1500);
//     tone(10, 450);
//    delay (500);
//    tone(10, 750);
//    delay (500);
//    tone(10, 950);
//    delay (500);
//  } 

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);
  servoRight.attach(12);
  pinMode(leftWhisker, INPUT); 
  pinMode(rightWhisker, INPUT);
                  // use the serial port
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int leftWhiskerValue = digitalRead(leftWhisker);
  int rightWhiskerValue = digitalRead(rightWhisker);

  moveKitty();
  if (leftWhiskerValue == 0 || rightWhiskerValue == 0 ) {
    stopKitty();
    delay (1500);
    moveKitty();
  }
}

