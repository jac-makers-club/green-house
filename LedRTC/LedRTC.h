#include <Arduino.h>
#include <RTClib.h>
#include <Arduino_MKRIoTCarrier.h>

class LedRTC
{
    // TODO:
    // How to / what happens if event is extended/modified?
    // How to make event happen everyday, not just at one date.

    RTC_DS3231 rtc;

    DateTime startTime;
    DateTime endTime;

    // Reference to the carrier in the main sketch (see class constructor).
    MKRIoTCarrier _carrier;

    void turnLightsON();
    void turnLightsOFF();

private:
    // Setup event for tomorrow. Add one day to the current startTime and endTime.
    void renewEvent();

public:
    void beginRTC();

    // Constructor w/ passing carrier by reference.
    // Carrier will be used to activate the relay.
    LedRTC(MKRIoTCarrier &carrier);

    // Turn lights on based on start and interval
    bool setLightInterval(DateTime onTime, TimeSpan interval);

    bool setLightHours(DateTime onTime, DateTime offTime);

    // Process light events
    void checkTime();

    // Expose the now method of RTC_DS3231 class
    DateTime now();
};
