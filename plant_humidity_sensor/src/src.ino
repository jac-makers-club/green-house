/*

*/
#include "Arduino_MCHPTouch.h"
#include <Arduino_MKRIoTCarrier.h>

int moistPin = A5;
MKRIoTCarrier carrier;
//Deviding the range in 4 parts so that the user has less guesswork to do
//These extra variables will most likely be unused and deleted but I just wanted to be sure in case we wanted to implement more ranges
int minMoisture = 670; //Completely wet
int oneThirdsMoisture = 758.25; //good moisture
int twoThirdsMoisture = 846.5; //Wet enough
int threeThirdMOisture = 934.75; //Somewhat wet
int maxMoisture = 1023; //Completely Dry
//Was 50
int moistureThreshold = 848;

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
  
  if(moistValue < moistureThreshold){
   //The moisture level is reaching wettest level (Could be problematic as too much water is bad)
    displayGoodHealth(moistValue);
  }
  else
    displayBadHealth(moistValue);
  
  delay(1000);
}


void displayGoodHealth(int moistureValue){
  
  //The LCD display
  carrier.display.fillScreen(ST77XX_GREEN);
  carrier.display.setTextColor(ST77XX_WHITE);
Serial.print("I'm in good health! Moisture: ");
  Serial.println(moistureValue);
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
