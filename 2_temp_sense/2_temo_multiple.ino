/*Multiple DS18B20 Temperature Sensors on 1 wire
  Connections:
  DS18B20 Pinout
  - Black wire   = Ground
  - Yellow wire = Signal (Pin 2):  (with 3.3K to 4.7K resistor to +5 or 3.3 )
  - Red wire  = +5 or +3.3 V
   
/*-----( Import needed libraries )-----*/
// Get 1-wire Library here: http://www.pjrc.com/teensy/td_libs_OneWire.html
#include <OneWire.h>

//Get DallasTemperature Library here:  http://milesburton.com/Main_Page?title=Dallas_Temperature_Control_Library
#include <DallasTemperature.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define ONE_WIRE_BUS_PIN 2

/*-----( Declare objects )-----*/
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS_PIN);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/*-----( Declare Variables )-----*/
// Assign the addresses of your 1-Wire temp sensors.

DeviceAddress Probe01 = { 0x28, 0xFF, 0x4B, 0xE3, 0x70, 0x17, 0x04, 0x1C };
DeviceAddress Probe02 = { 0x28, 0xFF, 0xD4, 0xD7, 0x70, 0x17, 0x04, 0x82 };
DeviceAddress Probe03 = { 0x28, 0xFF, 0x07, 0xD5, 0x70, 0x17, 0x04, 0x95 };
DeviceAddress Probe04 = { 0x28, 0xFF, 0x7A, 0x12, 0x62, 0x17, 0x03, 0x2D };


void setup()   /****** SETUP: RUNS ONCE ******/
{
  // start serial port to show results
  Serial.begin(9600);
  Serial.print("Initializing Temperature Control Library Version ");
  Serial.println(DALLASTEMPLIBVERSION);

  // Initialize the Temperature measurement library
  sensors.begin();

  // set the resolution to 10 bit (Can be 9 to 12 bits .. lower is faster)
  sensors.setResolution(Probe01, 10);
  sensors.setResolution(Probe02, 10);
  sensors.setResolution(Probe03, 10);
  sensors.setResolution(Probe04, 10);

}//--(end setup )---

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  delay(2000);
  Serial.println();
  Serial.print("Number of Devices found on bus = ");
  Serial.println(sensors.getDeviceCount());
  Serial.print("Getting temperatures... ");
  Serial.println();

  // Command all devices on bus to read temperature
  sensors.requestTemperatures();

  Serial.print("Probe 01 temperature is:   ");
  printTemperature(Probe01);
  Serial.println();

  Serial.print("Probe 02 temperature is:   ");
  printTemperature(Probe02);
  Serial.println();

   Serial.print("Probe 03 temperature is:   ");
  printTemperature(Probe03);
  Serial.println();

  Serial.print("Probe 04 temperature is:   ");
  printTemperature(Probe04);
  Serial.println();




}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/
void printTemperature(DeviceAddress deviceAddress)
{

float tempC = sensors.getTempC(deviceAddress);

   if (tempC == -127.00)
   {
   Serial.print("Error getting temperature  ");
   }
   else
   {
   Serial.print("C: ");
   Serial.print(tempC);
   Serial.print(" F: ");
   Serial.print(DallasTemperature::toFahrenheit(tempC));
   }
}// End printTemperature
//*********( THE END )***********
