#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Greenhouse"
  https://create.arduino.cc/cloud/things/f5473dcf-3ef3-4664-bc26-7d4c2c07897d 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int target_moisture;
  bool waterPump_activate;
  int moisture;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "Arduino_MKRIoTCarrier.h"
MKRIoTCarrier carrier;

int timer_delay = 2000;
int timer_start = 0;

int moisture_histeresys = 20;

void setup() {
  pinMode(A6, INPUT);

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  Serial.println("started");

  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  carrier.begin();
  carrier.display.print("Initializating");
  
  moisture = 100;

}

void loop() {
  ArduinoCloud.update();
  // Your code here 
   if(timer()){
    updateReadings();
    work();
  }
  
}

bool timer(){
  if ((millis() - timer_start) > timer_delay){
    timer_start = millis();
    return true;
  }else{
    return false;
  }

}
void work(){
  if(moisture > target_moisture - (moisture_histeresys / 2) ){
    water(false);

  } else if(moisture < target_moisture  + (moisture_histeresys / 2) ){
    water(true);
  }
}

void updateReadings(){
  //temperature = carrier.Env.readTemperature();
  moisture = analogRead(A6);

  Serial.println("Reading sensors");
  /*Serial.print("Temperature: \t");
  Serial.println(temperature);*/
  Serial.print("Moisture: \t");
  Serial.println(moisture);
  Serial.print("Target humid: \t");
  Serial.println(target_moisture);
}

void water(bool status){
  if (status){
    carrier.Relay1.open();
  }else{
    carrier.Relay1.close();
  }
}

/*
  Since WaterPumpActive is READ_WRITE variable, onWaterPumpActiveChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onWaterPumpActivateChange()  {
  // Add your code here to act upon WaterPumpActive change
    water(waterPump_activate);

}
/*
  Since TargetMoisture is READ_WRITE variable, onTargetMoistureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTargetMoistureChange()  {
  // Add your code here to act upon TargetMoisture change
}




