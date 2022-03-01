/*
Sketch based on RTC example from https://docs.arduino.cc/tutorials/generic/simple-rtc

This sketch sets the built-in RTC of the SAND51 (MKR wifi 1010) and writes the time 
to serial and the carrier screen every second.
*/

#include "Arduino_MCHPTouch.h"
#include <Arduino_MKRIoTCarrier.h>
#include <RTCZero.h>

MKRIoTCarrier carrier;
RTCZero rtc;

/* Change these values to set the current initial time */

const byte seconds = 0;
const byte minutes = 0;
const byte hours = 16;

/* Change these values to set the current initial date */
const byte day = 28;
const byte month = 2;
const byte year = 22;

void setup()
{
    Serial.begin(9600);
    rtc.begin(); // initialize RTC

    // Wait for a Serial Monitor without blocking if none is found
    delay(1000);

    CARRIER_CASE = false;
    carrier.begin();

    // Set the time
    rtc.setTime(hours, minutes, seconds);
    rtc.setDate(day, month, year);
}

void loop()
{

    // Print date...

    serialPrint2digits(rtc.getDay());
    Serial.print("/");

    serialPrint2digits(rtc.getMonth());
    Serial.print("/");

    serialPrint2digits(rtc.getYear());
    Serial.print(" ");

    // ...and time

    serialPrint2digits(rtc.getHours());
    Serial.print(":");

    serialPrint2digits(rtc.getMinutes());
    Serial.print(":");

    serialPrint2digits(rtc.getSeconds());
    Serial.println();

    displayTime();

    delay(1000);
}

void serialPrint2digits(int number)
{
    if (number < 10)
    {
        Serial.print("0"); // print a 0 before if the number is < than 10
    }
    Serial.print(number);
}

void carrierPrint2digits(int number)
{
    if (number < 10)
    {
        carrier.display.print("0"); // print a 0 before if the number is < than 10
    }
    carrier.display.print(number);
}

void displayTime()
{

    // The LCD display
    carrier.display.fillScreen(ST77XX_BLUE);
    carrier.display.setTextColor(ST77XX_WHITE);

    carrier.display.setCursor(0, 50);
    carrier.display.setTextSize(4);
    carrier.display.println("Date: ");

    carrierPrint2digits(rtc.getDay());
    carrier.display.print("/");

    carrierPrint2digits(rtc.getMonth());
    carrier.display.print("/");

    carrierPrint2digits(rtc.getYear());
    carrier.display.println("");

    // ...and time

    carrier.display.println("Time: ");

    carrierPrint2digits(rtc.getHours());
    carrier.display.print(":");

    carrierPrint2digits(rtc.getMinutes());
    carrier.display.print(":");

    carrierPrint2digits(rtc.getSeconds());
    carrier.display.println();
}