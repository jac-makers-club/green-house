#ifndef Pump_h
#define Pump_h

#include "Arduino.h"
#include <Arduino_MKRIoTCarrier.h>

class Pump{
  MKRIoTCarrier _carrier;
  
  public:
    Pump(MKRIoTCarrier &carrier);
    void TurnOn();
    void TurnOff();
    displayBadHealth();
    displayGoodHealth();
};

#endif
