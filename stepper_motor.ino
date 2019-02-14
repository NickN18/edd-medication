#include <Stepper.h>

const int stepsPerRev = 200; //change to fit the number of steps per revolution for motor

//initializes the stepper motor library on pins 8 through 11
Stepper testStep(stepsPerRev, 7, 8, 9, 10);

int stepCount = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  testStep.step(1);
  stepCount++;
  delay(500);
}
