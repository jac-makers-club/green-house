#include "Pump.h"

Pump::Pump(MKRIoTCarrier &carrier): _carrier{carrier}{
  moistPin = A5;
  Serial.println("Pump initialized");
}

void Pump::turnOff(){
  _carrier.Relay2.close();
}

void Pump::turnOn(){
  _carrier.Relay2.open();
}

void Pump::water(){
  const int NUMBER_OF_TRIES = 3;
  const int PUMP_TIME = 2000;
  const int DELAY_TIME = 2000;
  const float MOISTURE_THRESHOLD = 840;
  
  // Read the moisture
   float moisture = this->readMoisture();
   
  // For a number of tries, try watering the plant.
  for(int i = 0; i < NUMBER_OF_TRIES; i++){

    // If the thing is wet enough, stop
    if(moisture < MOISTURE_THRESHOLD)
      return;
      
    // Turn on the pump
    this->turnOn();
    delay(PUMP_TIME);
    this->turnOff();
    delay(DELAY_TIME);

    // Read sensor again
    moisture = this->readMoisture();
    Serial.println(moisture);
  }

  // If you're here, then the pump didn't water enough or has no water left.
  Serial.println("Done");
}

float Pump::readMoisture(){
  return analogRead(moistPin);
}

//void Pump::displayGoodHealth(int moistureValue){
//  Serial.print("I'm in good health! Moisture: ");
//  Serial.println(moistureValue);
//  
//  _carrier.display.fillScreen(ST77XX_GREEN);
//  _carrier.display.setTextColor(ST77XX_WHITE);
//  
//  _carrier.display.setCursor(30, 50);
//  _carrier.display.setTextSize(4);
//  _carrier.display.print("Moisture Level: ");
//  _carrier.display.setCursor(40, 120);
//  _carrier.display.print(moistureValue);
//}
//
//void Pump::displayBadHealth(int moistureValue){
//  Serial.print("I'm in bad health! Moisture: ");
//  Serial.println(moistureValue);
//
//  _carrier.display.fillScreen(ST77XX_RED);
//  _carrier.display.setTextColor(ST77XX_WHITE);
//
//  _carrier.display.setCursor(30, 50);
//  _carrier.display.setTextSize(4);
//  _carrier.display.print("Moisture Level: ");
//  _carrier.display.setCursor(40, 120);
//  _carrier.display.print(moistureValue);
//}
