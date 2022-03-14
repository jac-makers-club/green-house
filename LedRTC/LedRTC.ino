// Sample Arduino sketch that uses the experimental LedRTC library

#include <Arduino_MKRIoTCarrier.h>
#include "LedRTC.h"

MKRIoTCarrier carrier = MKRIoTCarrier();

LedRTC timer = LedRTC(carrier);

void setup()
{
    carrier.begin();
    Serial.begin(115200);
    delay(500);
    Serial.println("Starting Serial port");

    timer.beginRTC();

    DateTime now = timer.now();
    TimeSpan tenSecs = TimeSpan(10);

    timer.setLightInterval(now + tenSecs, tenSecs);
}

void loop()
{
    timer.checkTime();
    delay(500);
}