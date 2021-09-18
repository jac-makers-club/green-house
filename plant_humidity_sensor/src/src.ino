/*

*/
#include "Arduino_MCHPTouch.h"
#include <Arduino_MKRIoTCarrier.h>

int moistPin = A5;
MKRIoTCarrier carrier;
int minMoisture = 700;
int maxMoisture = 1023;
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
    displayGoodHealth(moistValue);
  else
    displayBadHealth(moistValue);
  
  delay(1000);
}

void displayGoodHealth(int moistureValue){
  Serial.print("I'm in good health! Moisture: ");
  Serial.println(moistureValue);
  //The LCD display
  carrier.display.fillScreen(ST77XX_ORANGE);
  carrier.display.setTextColor(ST77XX_WHITE);

  carrier.display.setCursor(30, 50);
  carrier.display.print("Moisture Level: ");
  carrier.display.setTextSize(4);
  carrier.display.setCursor(40, 120);
  carrier.display.print(moistureValue);
  
  
}

void displayBadHealth(int moistureValue){
  Serial.print("I'm in bad health! Moisture: ");
  Serial.println(moistureValue);

  carrier.display.fillScreen(ST77XX_RED);
  carrier.display.setTextColor(ST77XX_WHITE);

  carrier.display.setCursor(30, 50);
  carrier.display.print("Moisture Level: ");
  carrier.display.setTextSize(4);
  carrier.display.setCursor(40, 120);
  carrier.display.print(moistureValue);
}
