#include <Servo.h>                       	// Include servo library

Servo servoLeft;                          	// Declare left servo signal
Servo servoRight;                        	// Declare right servo signal

int PIEZOPIN = 8;     	

void blinkers3(){
  digitalWrite(3, HIGH);
  delay(120);
  digitalWrite(3, LOW);
  delay(120);
}

void blinkers7(){
  digitalWrite(7, HIGH);
  delay(120);
  digitalWrite(7, LOW);
  delay(120);
}

void blinkers11(){
  digitalWrite(11, HIGH);
  delay(120);
  digitalWrite(11, LOW);
  delay(120);
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

void forward() {
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(1500);
}

void backward() {
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(1500);
}


void setup() {

  tone(8, 1000, 1000);
  delay(1000);

  pinMode(8, OUTPUT);             	// Attach piezo to pin 5.

  servoLeft.attach(13);                  	// Attach left signal to pin 13
  servoRight.attach(12);                 	// Attach right signal to pin 1

  servoLeft.writeMicroseconds(1500);    	// Calibrate left servo
  servoRight.writeMicroseconds(1500);   	// Calibrate right servo
 
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  forward();
  backward();
  right();
  left();
  left();
  right();
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1500);
}

void loop() {
  blinkers3();
  blinkers7();
  blinkers11();
}
