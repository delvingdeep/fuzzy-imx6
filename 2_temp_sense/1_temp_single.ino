/*Code for using a single DS18b20 Temperature sensor*/

//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin number 2
#define ONE_WIRE_BUS 2

// Setting up a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Passing oneWire reference to Dallas Temperature for calculations.
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600); //Begins serial communication
  Serial.println("Arduino Digital Temperature // Serial Monitor Version"); //Prints a message
  sensors.begin();
}

void loop(void)
{
  // Sends the command to get temperatures
  sensors.requestTemperatures();

  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0)); // "byIndex" can specify IC number when using more than one IC on the same bus. 0 refers to the first IC on the wire

  delay(1000);  //Update value every 1 second

}
