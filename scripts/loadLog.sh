#!/bin/bash

# author= Deep Doshi

PORT="/dev/ttymxc3"
SKETCH="Arduino/ult_son/ult_son.ino"

SESSION="ult_son"

echo "------Uploading Sketch for ultrasonic sensor-----"
# Uses iMX.6 on-board SAM3X Arduino processor to upload sketch into
arduino --port $PORT --upload $SKETCH
echo "------Uploaded------"

echo "-------Starting data logging------"
# Putty session can have settings to load all serial data
# from the same serial port at some baud rate like 9600
# also can log data at some location with system parameters genearted
# unique names in format like .txt or .csv
putty -load $SESSION
