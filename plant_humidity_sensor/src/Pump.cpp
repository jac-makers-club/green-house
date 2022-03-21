#include "Pump.h"

Pump::Pump(MKRIoTCarrier &carrier): _carrier{carrier}{
  Serial.print("HELLO");
}

void TurnOff(){
  
}

void TurnOn(){
  
}

void displayGoodHealth(int moistureValue){
  
  //The LCD display
  _carrier.display.fillScreen(ST77XX_GREEN);
  carrier.display.setTextColor(ST77XX_WHITE);
  Serial.print("I'm in good health! Moisture: ");
  Serial.println(moistureValue);
  _carrier.display.setCursor(30, 50);
  _carrier.display.setTextSize(4);
  _carrier.display.print("Moisture Level: ");
  _carrier.display.setCursor(40, 120);
  _carrier.display.print(moistureValue);
  
  
}

void displayBadHealth(int moistureValue){
  Serial.print("I'm in bad health! Moisture: ");
  Serial.println(moistureValue);

  _carrier.display.fillScreen(ST77XX_RED);
  _carrier.display.setTextColor(ST77XX_WHITE);

  _carrier.display.setCursor(30, 50);
  _carrier.display.setTextSize(4);
  _carrier.display.print("Moisture Level: ");
  _carrier.display.setCursor(40, 120);
  _carrier.display.print(moistureValue);
}
