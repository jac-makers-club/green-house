/*

*/
#include "Arduino_MCHPTouch.h"
#include <Arduino_MKRIoTCarrier.h>

int moistPin = A5;
MKRIoTCarrier carrier;
int minMoisture = 0;
int maxMoisture = 100;
int moistureThreshold = 50;

void setup() {
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  
  CARRIER_CASE = false;
  carrier.begin();
}

void loop() {
  int rawMoistValue = analogRead(moistPin);
  int moistValue = rawMoistValue;
  
  if(moistValue > moistureThreshold)
    displayGoodHealth();
  else
    displayBadHealth(moistValue);
  
  delay(1000);
}

void displayGoodHealth(int moistureValue){
  Serial.println("I'm in good health! Moisture: " + moistureValue);
}

void displayBadHealth(int moistureValue){
  Serial.println("I'm in bad health! Moisture: " + moistureValue);
}
