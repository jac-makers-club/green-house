/*

*/
#include "Arduino_MCHPTouch.h"
#include <Arduino_MKRIoTCarrier.h>
#include "Pump.h"
#include <cstdio>
#include <functional>

int moistPin = A5;
MKRIoTCarrier carrier;
Pump* pump;

void setup() {
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  
  CARRIER_CASE = false;
  carrier.begin();

  // Initialize the led / pump classes
  pump = new Pump(carrier);

  // Initialize the scheduler
  // scheduler = new Scheduler();
    // Scheduler Init
        // Initialize an event list.
        // Make sure RTC time has been set.
  // Add the time events to the scheduler
  // scheduler.addEvent("8:00 PM", pump.water);
  // scheduler.addEvent("7:00 PM", led.on);
  // scheduler.addEvent("8:00 PM", led.off);
}

void loop() {
  // scheduler update call -> checks if an event has to run
  // scheduler.update();
  pump->water();
}
