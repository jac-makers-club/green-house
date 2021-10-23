#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

void setup()
{
    Serial.begin(115200);
    carrier.begin();

    // Make the touch buttons less sensitive (from 0 to 100). Trial and error.
    carrier.Buttons.updateConfig(50);
    updateDisplay();
}

void loop()
{
    // get the latest state of the buttons
    carrier.Buttons.update();

    if (carrier.Button3.getTouch())
    {
        Serial.println("Button 3 Touched");
        updateDisplay();
    }
    if (carrier.Button1.getTouch())
    {
        Serial.println("Button 1 Touched");
        toogleRelay(carrier.Relay1);
        updateDisplay();
    }
    if (carrier.Button2.getTouch())
    {
        Serial.println("Button 2 Touched");
        toogleRelay(carrier.Relay2);
        updateDisplay();
    }

    delay(200); // to de-bounce the touch sensors
}

// Use & to access the relay with 'pass by reference' 
void toogleRelay(MKRIoTCarrier_Relay &relay)
{
    if (relay.getStatus() == HIGH) // Normally Open position
    {
        relay.close();
        Serial.println("Relay " + String(relay.getPin()) + " is ON");
    }
    else { // Normally Closed position
        relay.open(); 
        Serial.println("Relay " + String(relay.getPin()) + "is OFF");
    }
}

void updateDisplay()
{
    carrier.display.fillScreen(ST77XX_WHITE);
    carrier.display.setTextColor(ST77XX_RED);
    carrier.display.setTextSize(3);
    carrier.display.setTextColor(ST77XX_BLUE);
    carrier.display.setCursor(20, 120);

    carrier.display.print("R1: ");
    carrier.display.print(carrier.Relay1.getStatus());
    carrier.display.print(" R2: ");
    carrier.display.print(carrier.Relay2.getStatus());
}
