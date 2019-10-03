
// AccelStepper - Version: Latest 
#include <AccelStepper.h>
#include <MultiStepper.h>

#include <ESP8266Wifi.h>
#include <Arduino.h>
#include <ESP8266WifiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WifiClient.h>

//const int stepsPerRev = 200; //change to fit the number of steps per revolution for motor

ESP8266WifiMulti WifiMulti;

#define HALFSTEP 8

const int limitPin = 7;

int limitState = 0;

#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11

//initializes the stepper motor library on pins 8 through 11
AccelStepper testStep(HALFSTEP, motorPin1, motorPin2, motorPin3, motorPin4);

int revCheck = 0; //0 for no revolution done, 1 for a revolution made
int revolution = 4096/2; // revolution measure

int userTime;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  
  Serial.println();
  Serial.println();
  Serial.println();
  
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] Wait %d...\n", t);
    Serial.flush();
    delay(1000);
  }
  
  Wifi.mode(WIFI_STA);
  WifiMulti.addAP("Noriega5-5G", "Alexandria288");
  
  pinMode(limitPin, INPUT);
  
  testStep.setMaxSpeed(10000.0);
  testStep.setAcceleration(1000.0);
  testStep.setSpeed(50);
  testStep.moveTo(revolution/4); // 1/8 of a full revolution

}

void loop() {
  
  userTime = digitalRead(limitState);
  Serial.print(userTime);
  Serial.println();
  String myString = "https://edd-medicine-dispenser-1-epicslayer18.c9users.io/medication-dispenser/selectMedication.php";
  String finalString = myString + userTime;
  Serial.print(finalString);
  
  if ((WiFiMulti.run() == WL_CONNECTED)) {
  Serial.print(userTime);
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, finalString)) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

  delay(1000);
 
  
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
