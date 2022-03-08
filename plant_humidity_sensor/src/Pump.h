#ifndef Pump_h
#define Pump_h

#include "Arduino.h"
#include <Arduino_MKRIoTCarrier.h>

class Pump{
  public:
    Pump();
    void TurnOn();
    void TurnOff();
  private:
    MKRIoTCarrier carrier;
};

#endif
