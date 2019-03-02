
// AccelStepper - Version: Latest 
#include <AccelStepper.h>
#include <MultiStepper.h>

//const int stepsPerRev = 200; //change to fit the number of steps per revolution for motor

#define HALFSTEP 8

#define limitPin 7

#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11

//initializes the stepper motor library on pins 8 through 11
AccelStepper testStep(HALFSTEP, motorPin1, motorPin2, motorPin3, motorPin4);

int revCheck = 0; //0 for no revolution done, 1 for a revolution made
int revolution = 4096/2; // revolution measure

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  pinMode(limitPin, INPUT);
  
  testStep.setMaxSpeed(10000.0);
  testStep.setAcceleration(1000.0);
  testStep.setSpeed(50);
  testStep.moveTo(revolution/4); // 1/8 of a full revolution

}

void loop() {
  //prints the current position of the motor to the Serial monitor
  Serial.println(testStep.currentPosition());

  testStep.run();
  
  while(revCheck == 0) {
    if(testStep.currentPosition() == 2038 && revCheck == 1) {
      testStep.moveTo(0.0);
      revCheck = 0;
    } else {
      if(testStep.distanceToGo() == 0) {
        testStep.stop();
      } else {
        testStep.run();
      }
    }
  }  

    
  Serial.println(testStep.currentPosition());




/*  
  
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  if(motorSpeed > 0) {
    testStep.setSpeed(motorSpeed);
    testStep.step(stepsPerRev / 100);
  }
*/ 
}
