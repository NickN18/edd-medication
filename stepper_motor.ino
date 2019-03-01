https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#a748665c3962e66fbc0e9373eb14c69c1

#include <Stepper.h>
#include <AccelStepper.h>

//const int stepsPerRev = 200; //change to fit the number of steps per revolution for motor

#define HALFSTEP 8

#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11

//initializes the stepper motor library on pins 8 through 11
AccelStepper testStep(HALFSTEP, motorPin1, motorPin2, motorPin3, motorPin4);

int stepCount = 0;

void setup() {
  // put your setup code here, to run once:

  testStep.setMaxSpeed(1.0);
  testStep.setAcceleration(0.5);
  testStep.moveTo(680.0);
  testStep.setSpeed(50);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(testStep.distanceToGo() == 0) {
    testStep.moveTo(0.0);
  }

if(stepCount < 8) {
  testStep.run();
  stepCount++;
} else (
  testStep.moveTo(0.0);
  stepCount = 0;
  testStep.run();
}
  
  
 /*  
  
  int sensorReading = analogRead(A0);

  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);

  if(motorSpeed > 0) {
    testStep.setSpeed(motorSpeed);

    testStep.step(stepsPerRev / 100);
  }

*/ 
}
