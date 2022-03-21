/*

*/
#include "Arduino_MCHPTouch.h"
#include <Arduino_MKRIoTCarrier.h>
#include "Pump.h"

int moistPin = A5;
MKRIoTCarrier carrier;
Pump pump;
//Deviding the range in 4 parts so that the user has less guesswork to do
//These extra variables will most likely be unused and deleted but I just wanted to be sure in case we wanted to implement more ranges
int minMoisture = 670; //Completely wet
int oneThirdsMoisture = 758.25; //good moisture
int twoThirdsMoisture = 846.5; //Wet enough
int threeThirdMOisture = 934.75; //Somewhat wet
int maxMoisture = 1023; //Completely Dry
//Was 50
int moistureThreshold = 848;
int lastMoisture = -1;

void setup() {
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  
  CARRIER_CASE = false;
  //carrier.begin();
  
}

void loop() {
  
}
