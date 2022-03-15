#include "LedRTC.h"

// Initialize member carrier using 'member initialization list'
// This is required because we cannot re-assign the reference
// ei. _carrier = carrier
LedRTC::LedRTC(MKRIoTCarrier &carrier) : // Using brace initialization systax (also called list initialization).
                                         _carrier{carrier}
{
    // Do nothing for now (carrier might not have initialized yet).
    // Initialize default values in beginRTC()
}

void LedRTC::beginRTC()
{
    Serial.println("Constructing LedRTC");

    // Relay in open position by default
    _carrier.Relay1.close();

    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
        Serial.flush();
        while (1)
            delay(10);
    }

    if (rtc.lostPower())
    {
        Serial.println("RTC lost power, let's set the time!");
        // When time needs to be set on a new device, or after a power loss, the
        // following line sets the RTC to the date & time this sketch was compiled
        
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        // This line sets the RTC with an explicit date & time, for example to set
        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }
    DateTime startTime = rtc.now();
    DateTime endTime = rtc.now();
}

void LedRTC::renewEvent()
{

    // Assignment operator += has not been overloaded so is not available
    startTime = startTime + TimeSpan(1, 0, 0, 0);
}

// Turn lights on based on start and interval
bool LedRTC::setLightInterval(DateTime onTime, TimeSpan interval)
{
    startTime = onTime;
    endTime = startTime + interval;

    Serial.print("Start time: ");
    Serial.println(startTime.timestamp());
    Serial.print("End time: ");
    Serial.println(endTime.timestamp());
}

bool LedRTC::setLightHours(DateTime onTime, DateTime offTime)
{
    startTime = onTime;
    endTime = offTime;
}

// Process light events
void LedRTC::checkTime()
{
    Serial.println("Checking time");

    DateTime now = rtc.now();

    if ((now > startTime) && (now < endTime))
    {
        Serial.println("Lights ON");
        turnLightsON();
    }
    else if (now > endTime)
    {
        Serial.println("Lights OFF");
        turnLightsOFF();
    }
}

void LedRTC::turnLightsON()
{
    _carrier.Relay1.open();
}

void LedRTC::turnLightsOFF()
{
    _carrier.Relay1.close();
}

// Expose the now method of RTC_DS3231 class
DateTime LedRTC::now()
{
    return rtc.now();
}