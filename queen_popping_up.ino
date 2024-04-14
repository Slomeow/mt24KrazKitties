#include <Servo.h>

Servo myservo;  //cat spin


const int buttonPin = 2; //alice steps on spot on ground to activate button
int buttonVal;
int pos = 0;

void setup() {
  myservo.attach(9);  //attaches queen servo to pin 9
  pinMode(buttonPin, INPUT);
}

//servo is put horizontally
//using the half servo top (extending only on one side)
//sweeping motion
void loop() {
  if(digitalRead(buttonPin) == LOW){
   pos = 90;
    myservo.write(pos);              
    delay(15);             
   
    }else{
      pos = 220;
       delay(15);
      myservo.write(pos);  
  }
}