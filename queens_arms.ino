#include <Servo.h>

Servo myservo;  //queen's arms

//either side of the servo is attached to the queens arms and they move up and down

const int buttonPin = 2; 
int buttonVal;
int pos = 0;

void setup() {
  myservo.attach(9);  
  pinMode(buttonPin, INPUT);
}

void loop() {
  if(digitalRead(buttonPin) == LOW){
   pos = 70;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);             
   
    }else{
      pos = 110;
       delay(15);
      myservo.write(pos);  
  }
}
