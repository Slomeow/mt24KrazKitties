#include <Servo.h>

Servo queenpop;  //queen poppinng up servo

const int buttonPin = 2; //the pin where electricity wil flow to the wires
//int buttonVal;
int buttonState = 0;
int previousButtonState = 0;

void setup() {
  queenpop.attach(9);  //attaches alice servo to pin 9

  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != previousButtonState) {
    if (buttonState == HIGH) {
      Serial.println("button presseed");
      queenpop.write(180);
    }else{
      Serial.println("button released");
    }
  }
  previousButtonState = buttonState;
}
