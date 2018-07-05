#include <Servo.h>                           // Include servo library

Servo servoRight;
Servo servoLeft;

int leftWhisker = 5;
int rightWhisker = 7;
int PIEZOPIN = 4; 
int aValue = digitalRead(leftWhisker);
int bValue = digitalRead(rightWhisker); 

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

void moveKitty() {
  // Your Code Here
servoLeft.writeMicroseconds(1700);        
servoRight.writeMicroseconds(1700);
  
}

void toneThree(){
  tone(4, 659, 1000);
delay(1000); 
tone(4, 523, 1000);
delay(1000); 
 tone(4, 784, 1000);
delay(1000); 
tone(4, 587, 1000);
delay(1000); 
tone(4, 659, 1000);
delay(1000); 
}

void stopKitty() {
  // Your Code Here
    servoLeft.writeMicroseconds(1500);        
    servoRight.writeMicroseconds(1500);
  
  
}

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(leftWhisker, INPUT);
pinMode(rightWhisker, INPUT);
pinMode(PIEZOPIN, OUTPUT);                 // Attach piezo to pin 5. 
servoLeft.attach(13);                      // Attach left signal to pin 13
servoRight.attach(12);                     // Attach right signal to pin 12
servoLeft.writeMicroseconds(1500);        // Calibrate left servo
servoRight.writeMicroseconds(1500);       // Calibrate right servo
  //Your Code Here
}

void loop() {
 // put your main code here, to run repeatedly:
  int aValue = digitalRead(leftWhisker);
  int bValue = digitalRead(rightWhisker);
  moveKitty(); 
  if (aValue == 0 && bValue == 0){
    stopKitty();
    toneThree();
  }
  moveKitty();
  //Your Code Here
}

