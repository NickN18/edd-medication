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

  testStep.setMaxSpeed(1000.0);
  testStep.setAcceleration(100.0);
  testStep.setSpeed(200);
  testStep.moveTo(4096 / 2);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(testStep.distanceToGo() == 0) {
    testStep.moveTo(-testStep.currentPosition());
  }

testStep.run();
  
/*  
  
  int sensorReading = analogRead(A0);

  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);

  if(motorSpeed > 0) {
    testStep.setSpeed(motorSpeed);

    testStep.step(stepsPerRev / 100);
  }

*/ 
}
