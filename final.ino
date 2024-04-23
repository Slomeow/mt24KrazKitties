#include <Servo.h>

// Servo objects
Servo doorservo;   // door opening spin servo
Servo catservo;    // cat switches to moon servo
Servo queenservo;  // queen pops up servo
Servo armservo;    // arms moving servo

// Button pins
const int doorButtonPin = 2;
const int CatButtonPin = 3;
const int queenButtonPin = 4;
const int armsButtonPin = 5;

const int ledButtonPin = A0;

//LED pins
const int LED_blue1 = 10;   // The first blue pin
const int LED_white1 = 11;  // The white pin
const int LED_blue2 = 12;   // 2nd blue pin
const int LED_first = 13;   //1st LED

int blinkState = LOW; 


// Button states
int doorButtonState = 0;
int previousdoorButtonState = 0;
int CatButtonState = 0;
int previousCatButtonState = 0;
int queenButtonState = 0;
int previousqueenButtonState = 0;

int ledButtonState = 0;
int previousledButtonState = 0;

void setup() {
  // Attach servos
  doorservo.attach(6);
  catservo.attach(7);
  queenservo.attach(8);
  armservo.attach(9);

  // Set button pins as input
  pinMode(doorButtonPin, INPUT);
  pinMode(CatButtonPin, INPUT);
  pinMode(queenButtonPin, INPUT);
  pinMode(armsButtonPin, INPUT);

  // Set LED pins as output
  pinMode(LED_blue1, OUTPUT);
  pinMode(LED_white1, OUTPUT);
  pinMode(LED_blue2, OUTPUT);
  pinMode(LED_first, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);

  // Initial servo positions
  catservo.write(180);
  doorservo.write(0);
  queenservo.write(0);
  armservo.write(0);
}

void loop() {

  //LED interactions
  if (blinkState == LOW) {
    blinkState = HIGH;
  } else {
    blinkState = LOW;
  }
  // set the LED with the ledState of the variable:
  digitalWrite(LED_first, blinkState);
  //LED Travel line
  ledButtonState = digitalRead(ledButtonPin);
  if (ledButtonState !=previousledButtonState) {
    if (ledButtonState== HIGH){
      digitalWrite(LED_blue1, HIGH);
  delay(1000);
  digitalWrite(LED_blue1, LOW);
  delay(10);
  digitalWrite(LED_white1, HIGH);
  delay(1000);
  digitalWrite(LED_white1, LOW);
  delay(10);
  digitalWrite(LED_blue2, HIGH);
  delay(1000);
  digitalWrite(LED_blue2, LOW);
  delay(10);
    } else {
       Serial.println("led button released");
    }
  }
    previousledButtonState = ledButtonState;
    
  
  //door opening interaction
  doorButtonState = digitalRead(doorButtonPin);
  if (doorButtonState != previousdoorButtonState) {
    if (doorButtonState == HIGH) {
      Serial.println("door button pressed");
      doorservo.write(90);
    } else {
      Serial.println("door button released");
    }
  }
  previousdoorButtonState = doorButtonState;

  // cat to moon interaction
  CatButtonState = digitalRead(CatButtonPin);
  if (CatButtonState != previousCatButtonState) {
    if (CatButtonState == HIGH) {
      Serial.println("Cat button pressed");
      for (int pos = 180; pos >= 0; pos -= 1) {
        catservo.write(pos);
        delay(15);
      }
    } else {
      Serial.println("Cat button released");
      delay(15);
    }
  }
  previousCatButtonState = CatButtonState;

  // queen popping up
  queenButtonState = digitalRead(queenButtonPin);
  if (queenButtonState != previousqueenButtonState) {
    if (queenButtonState == HIGH) {
      Serial.println("queen button pressed");
      queenservo.write(90);
    } else {
      Serial.println("queen button released");
    }
  }
  previousqueenButtonState = queenButtonState;

  //arms moving interaction
  if (digitalRead(armsButtonPin) == HIGH) {
    for (int pos = 65; pos <= 115; pos += 1) {
      armservo.write(pos);
      delay(15);
    }
    for (int pos = 115; pos >= 65; pos -= 1) {
      armservo.write(pos);
      delay(15);
    }
  }
}