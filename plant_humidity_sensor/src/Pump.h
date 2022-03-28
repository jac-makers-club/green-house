#ifndef Pump_h
#define Pump_h

#include "Arduino.h"
#include <Arduino_MKRIoTCarrier.h>

class Pump{
  MKRIoTCarrier _carrier;
  int moistPin;
//  void displayBadHealth();
//  void displayGoodHealth();
  private:
    void turnOff();
    void turnOn();
    float readMoisture();
  public:
    Pump(MKRIoTCarrier &carrier);
    void water();
};

#endif
