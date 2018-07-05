#include <Servo.h>                           // Include servo library

int PIEZOPIN = 4;

Servo servoRight;
Servo servoLeft;

int leftWhisker = 5;
int rightWhisker = 7;

int note_A4 = 440;
int note_As4 = 466; int note_Bb4 = note_As4;
int note_B4 = 494;
int note_C5 = 523;
int note_Cs5 = 554; int note_Db5 = note_Cs5;
int note_D5 = 587;
int note_Ds5 = 622; int note_Eb5 = note_Ds5;
int note_E5 = 659;
int note_F5 = 698;
int note_Fs5 = 740; int note_Gb5 = note_Fs5;
int note_G5 = 784;
int note_Gs5 = 830; int note_Ab5 = note_Gs5;


void moveKittyf(){
  // Your Code Here
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(1500);

   tone(4, 430, 100);
   delay(100);
}

   
void moveKittyb() {
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(1500);
}

void stopKitty() {
  int leftWhiskerV = digitalRead(leftWhisker);
  int rightWhiskerV = digitalRead(rightWhisker);
  if(leftWhiskerV == 0) {
   tone(4, 440, 100);
   delay(100);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(1500);  
} else if(rightWhiskerV == 0) {
   tone(4, 450, 100);
   delay(100);
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(1500);
} else if(leftWhiskerV == 0 && rightWhiskerV == 0){
   tone(4, 460, 100);
   delay(100);
  delay(1500);
}
}

void setup() {
pinMode(leftWhisker, INPUT);
pinMode(rightWhisker, INPUT);
servoLeft.attach(13);
servoRight.attach(12);
moveKittyf();
moveKittyb();
stopKitty();


}

void loop() {
 int leftWhiskerV = digitalRead(leftWhisker);
  int rightWhiskerV = digitalRead(rightWhisker);
  if(leftWhiskerV == 0) {
   tone(4, 440, 100);
   delay(100);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(500);  
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(500);
} else if(rightWhiskerV == 0) {
   tone(4, 450, 100);
   delay(100);
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(500);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(500);
} else if(leftWhiskerV == 0 && rightWhiskerV == 0){
   tone(4, 460, 100);
   delay(100);
  delay(1500);
}
}
