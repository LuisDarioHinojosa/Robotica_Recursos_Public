from importlib.resources import path
import serial
import os

def decodeSerial(ser):
    serialString = ser.readline()
    serialString = serialString.decode('utf-8')
    serialString = serialString.split()
    return serialString


folder = "MediaFiles"
fileInput = input("Enter Filename:")
f = f"{fileInput}.txt"


baudRate = 9600
com = 'COM9'

ser = serial.Serial(com,baudRate)

ser.close()

ser.open()


stuff = "-"
while stuff[0] != "Start":
    stuff = decodeSerial(ser)
    continue
if not os.path.exists(folder):
    os.mkdir(folder)

os.chdir(folder)
if os.path.exists(f):
    os.remove(f)

with open(f,'w+') as file:
    while stuff[0] != "End":
        if stuff[0] == "End":
            break
        stuff = decodeSerial(ser)
        file.write(f"{stuff[0]} \n")

file.close()
ser.close()

