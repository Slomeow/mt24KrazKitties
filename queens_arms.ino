#include <Servo.h>

Servo queenarm; // queen's arms moving 
int servoPin = 9; 
int buttonPin = 2; 

void setup() {
 queenarm.attach(servoPin); 
 pinMode(buttonPin, INPUT);
}

void loop() {
 if (digitalRead(buttonPin) == HIGH) { 
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
