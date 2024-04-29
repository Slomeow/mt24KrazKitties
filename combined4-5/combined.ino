#include <Servo.h>

Servo queenpop; //queen popping up servo
Servo queenarm; //queen's arms moving servo

const int buttonPinPop = 10; //switch: queen popping up
const int buttonPinArm = 2; //switch: queen's arms moving 

int buttonStatePop = 0;
int previousButtonStatePop = 0;
int buttonStateArm = 0;

void setup() {
 queenpop.attach(3); //queen popping up servo to pin 3
 queenarm.attach(9); //queen's arms moving servo to pin 9

 pinMode(buttonPinPop, INPUT);
 pinMode(buttonPinArm, INPUT);

 Serial.begin(9600);
}

void loop() {
 // queen popping up
 buttonStatePop = digitalRead(buttonPinPop);
 if (buttonStatePop != previousButtonStatePop) {
    if (buttonStatePop == HIGH) {
      Serial.println("Queen pop button pressed");
      queenpop.write(180);
    } else {
      Serial.println("Queen pop button released");
    }
 }
 previousButtonStatePop = buttonStatePop;

 // queen's arms moving
 buttonStateArm = digitalRead(buttonPinArm);
 if (buttonStateArm == HIGH) {
    for (int pos = 65; pos <= 115; pos += 1) {
      queenarm.write(pos);
      delay(15);
    }
    for (int pos = 115; pos >= 65; pos -= 1) {
      queenarm.write(pos);
      delay(15);
    }
 }
}