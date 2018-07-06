#include <Servo.h>                         // Include servo library
Servo servoLeft;                            // Declare left servo signal
Servo servoRight;                         // Declare right servo signal
int leftWhisker = 5;
int rightWhisker = 7;

int PIEZOPIN = 3; 
void turnleft() {
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(1500);
}
void turnright() {
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
int leftWhiskerV = digitalRead(leftWhisker);
int rightWhiskerV = digitalRead(rightWhisker);
  
void hitL() {
  turnright();
}
void hitR() {
  turnleft();
}
void hitF() {
  backward();
  turnleft();
}
void setup() {
tone(3, 440, 100);
delay(1000);
tone(3, 523, 100);
delay(1000);
tone(3, 523, 100);
delay(1000);
tone(3, 850, 100);
delay(1000);
tone(3, 466, 100);
delay(1000);
pinMode(8, OUTPUT);       
pinMode(leftWhisker, INPUT);
pinMode(rightWhisker, INPUT);
servoLeft.attach(13);                    // Attach left signal to pin 13
servoRight.attach(12);                  // Attach right signal to pin 1
servoLeft.writeMicroseconds(1500);      // Calibrate left servo
servoRight.writeMicroseconds(1500);     // Calibrate right servo
Serial.begin(9600);
}

void loop() {
  int leftWhiskerV = digitalRead(leftWhisker);
  int rightWhiskerV = digitalRead(rightWhisker);
//  forward();
  if(leftWhiskerV == 0 && rightWhiskerV == 0){
  Serial.print(leftWhiskerV);
  hitF();
  } else if(rightWhiskerV == 0) {
  hitR();
  } else if(leftWhiskerV == 0) {
  hitL();  
  }else {
    forward();
  }
tone(3, 440, 100);
delay(1000);
tone(3, 494, 100);
delay(1000);
tone(3, 523, 100);
delay(1000);
tone(3, 587, 100);
delay(1000);
tone(3, 659, 100);
delay(1000);
}
