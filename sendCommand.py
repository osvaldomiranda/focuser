#!/usr/bin/python

import sys
import time
import serial 

print('Argument List:', str(sys.argv[1]))

ser=serial.Serial(port='/dev/cu.usbserial-A700G2J9',baudrate=9600,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS,timeout=1)
ser.flushInput
time.sleep(2)
if sys.argv[1]=="-a" :
  ser.write(b'a')
  print('A', str(sys.argv[1]))
else:
  ser.write(b'r')  
  print('R:', str(sys.argv[1]))
ser.flushOutput()


ser.close
print("write data")

