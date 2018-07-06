#include <Servo.h>
Servo servoRight;
Servo servoLeft; 

int leftWhisker = 5;
int rightWhisker = 7;

void straight () {
  digitalWrite (9, HIGH);
  tone(2,450);
  delay (100);
  tone (2, 750);
  delay (100);
  servoLeft.writeMicroseconds (1700);
  servoRight.writeMicroseconds (1300);
}

void turnright () {
  noTone(2);
  digitalWrite (9, LOW);
  digitalWrite (10, HIGH);
  servoLeft.writeMicroseconds (1500);
  servoRight.writeMicroseconds (1500) ; 
  delay (500) ;
  servoLeft.writeMicroseconds (1300);
  servoRight.writeMicroseconds (1700);
  delay (200) ; 
  digitalWrite (10, LOW);
  digitalWrite (1, HIGH);
  servoLeft.writeMicroseconds (1300); // turn counterclockwise
  servoRight.writeMicroseconds (1300);
  delay(675);
  servoLeft.writeMicroseconds (1500);
  servoRight.writeMicroseconds (1500);
  delay(500);
  digitalWrite (1, LOW);
}

void turnleft () {
  noTone(2);
  digitalWrite (9, LOW);
  digitalWrite (10, HIGH);
  servoLeft.writeMicroseconds (1500);
  servoRight.writeMicroseconds (1500) ; 
  delay (500) ;
  servoLeft.writeMicroseconds (1300);
  servoRight.writeMicroseconds (1700);
  delay (200) ; 
  digitalWrite (10, LOW);
  digitalWrite (1, HIGH);
  servoLeft.writeMicroseconds (1700); // turn clockwise
  servoRight.writeMicroseconds (1700);
  delay(675);
  servoLeft.writeMicroseconds (1500);
  servoRight.writeMicroseconds (1500);
  delay(500);
  digitalWrite (1, LOW);
}




void setup() {
 servoLeft.attach(13);
 servoRight.attach(12);
 pinMode (leftWhisker, INPUT);
 pinMode (rightWhisker, INPUT);
 pinMode (1, OUTPUT);
 pinMode (10, OUTPUT);  
 pinMode(9, OUTPUT);
}

void loop() {
  int leftWhiskerValue = digitalRead (leftWhisker);
  int rightWhiskerValue = digitalRead (rightWhisker);

  straight();
  if (leftWhiskerValue == 0 && rightWhiskerValue != 0) {
    turnleft();
    delay (1500);
    straight();
  }
  if (rightWhiskerValue == 0 && leftWhiskerValue != 0) {
    turnright();
    delay (1500);
    straight();
  }
  if (leftWhiskerValue == 0 && rightWhiskerValue == 0) {
    turnleft();
    delay (1500);
    straight();
  }
  
}
