/*

*/
#include "Arduino_MCHPTouch.h"
#include <Arduino_MKRIoTCarrier.h>
#include "Pump.h"

int moistPin = A5;
MKRIoTCarrier carrier;
Pump* pump;

void setup() {
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  
  CARRIER_CASE = false;
  carrier.begin();
  pump = new Pump(carrier);
}

void loop() {
  pump->water();
}
