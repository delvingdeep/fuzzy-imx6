# fuzzy-imx6

A repository which contains some of the NXP iMX.6 based Ubuntu and on-board Arduino programs.

Here I am using Freescale NXP [iMX.6 quad](https://www.nxp.com/products/microcontrollers-and-processors/arm-based-processors-and-mcus/i.mx-applications-processors/i.mx-6-processors/i.mx-6quad-processors-high-performance-3d-graphics-hd-video-arm-cortex-a9-core:i.MX6Q) processor based board from [Udoo](https://www.udoo.org/docs/Introduction/Introduction.html).

On Udoo iMX.6 quad, Linaro Ubuntu can be hosted. This [link](https://www.udoo.org/get-started-quaddual/) can be used for setting up LUbuntu on it.

In order to get display of the console/GUI, a HDMI screen or a LCD can be used.

- For LCD screen, execute
```
sudo udooscreenctl set lvds7    #for 7inch LCD
sudo udooscreenctl set lvds15   #for 5inch LCD
```

- For HDMI screen, exceute
```
sudo udooscreenctl set hdmi
```

This board also has a SAM3X, which is a Arduino compatible processor. To flash any program, use Arduino IDE on LUbuntu GUI and select _com port_ as `/dev/ttymxc3`.

This repository contains code for
1) Basic programs:
- LED Blinking
- Servo Motor control
2) Temperature Sensor
3) OpenCV based Face detection

In case of any queires or feedback, [contact me](mailto:deepdoshi@live.in)

###### \*STATUS: Under development
