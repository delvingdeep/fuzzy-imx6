Here I am using a DS18b20 Waterproof Temperature sensor from [Maxim](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf), bought at [Amazon](https://www.amazon.com/dp/B0184WW06W/ref=asc_df_B0184WW06W5245956/?tag=hyprod-20&creative=395033&creativeASIN=B0184WW06W&linkCode=df0&hvadid=198072959016&hvpos=1o2&hvnetw=g&hvrand=1065140709317627955&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032008&hvtargid=pla-319313556210)

It is a oneWire sensor and so we can use Maxim's [OneWire Libary](https://github.com/PaulStoffregen/OneWire) for it.

For simplifying temperature conversion calculations, I am using Milesburton's [DallasTemperature](https://www.milesburton.com/Dallas_Temperature_Control_Library) library, can be found on [here](https://github.com/milesburton/Arduino-Temperature-Control-Library) on there Github page.

Downlaod the zip file for both libraries, and then  go to Arduino IDe to add libaries. Once libraries are added, they can be used as:
```
#include<OneWire.h>
#include<DallasTemperature.h>
```
