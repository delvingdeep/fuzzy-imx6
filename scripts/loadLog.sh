#!/bin/bash

# author: Deep Doshi

# Defining some variables
PORT="/dev/ttymxc3"                     #COM PORT for arduino to upload sketch
SKETCH="Arduino/ult_son/ult_son.ino"    #Path for Arduino sketch
SESSION="ult_son"                       #Putty saved session

echo "----------Uploading Sketch----------"
# Uses iMX.6 on-board SAM3X Arduino processor to upload sketch into
arduino --port $PORT --upload $SKETCH
echo "----------Uploaded----------"

echo "----------Starting data logging----------"
# Putty session can have settings to load all serial data
# from the same serial port at some baud rate like 9600
# also can log data at some location with system parameters genearted
# unique names in format like .txt or .csv
putty -load $SESSION
