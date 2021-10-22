#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

bool relay_1 = false;
bool relay_2 = false;
String relayState1 = "OFF";
String relayState2 = "OFF";

void setup()
{
    // Initialize serial and wait for port to open:
    Serial.begin(115200);
    // This delay gives the chance to wait for a Serial Monitor without blocking if none is found

    carrier.begin();
    delay(200);
    onUpdateDisplayChange();
}

void loop()
{
    carrier.Buttons.update();

    if (carrier.Button3.getTouch())
    {
        Serial.println("Button 3 Touched");
        onUpdateDisplayChange();
    }

    if (carrier.Button1.getTouch())
    {
        Serial.println("Button 1 Touched");
        // Toogle the value of relay_1
        toogleRelay1();
        onUpdateDisplayChange();
    }

    if (carrier.Button2.getTouch())
    {
        Serial.println("Button 2 Touched");
        // Toogle the value of relay_1
        toogleRelay2();
        onUpdateDisplayChange();
    }

    delay(200);
}

void toogleRelay1()
{    
    if (relay_1)
    {
        relay_1 = false;
        relayState1 = "OFF";
        carrier.Relay1.open();
        Serial.println("relay 1 is OFF");
    }
    else
    {
        relay_1 = true;
        relayState1 = "ON";
        carrier.Relay1.close();
        Serial.println("relay 1 is ONs");
    }
}

void toogleRelay2()
{    
    if (relay_2)
    {
        relay_2 = false;
        relayState2 = "OFF";
        carrier.Relay2.open();
        Serial.println("relay 2 is OFF");
    }
    else
    {
        relay_2 = true;
        relayState2 = "ON";
        carrier.Relay2.close();
        Serial.println("relay 2 is ON");
    }
}

void onUpdateDisplayChange()
{
  carrier.display.fillScreen(ST77XX_WHITE);
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.setTextSize(2);

  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setCursor(20, 120);
  carrier.display.print("R1: ");
  carrier.display.print(relayState1);

  carrier.display.print(" R2: ");
  carrier.display.print(relayState2);
}
