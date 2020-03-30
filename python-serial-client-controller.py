#import statements
import serial, sys, time

#the device that the program will be connecting to by serial
SERIAL_DEVICE = str(sys.argv[-1])

#set up the serial with the arduino board
arduinoSerial = serial.Serial(SERIAL_DEVICE, 9600)

#wait 3 seconds for the board to initialize
time.sleep(3)

#the characters to move the machines legs (lowercase is one direction uppercase is another)
MACHINE_LEG_MOVEMENT_CHARS = [
    'a', 'b',
    'c', 'd'
]

#the characters to reset the machines legs
MACHINE_LEG_RESET_CHARS = [
    '1', '2',
    '3', '4'
]

#function to reset the machines legs
def resetLegs():
    
    #import global variables that are needed
    global arduinoSerial, MACHINE_LEG_RESET_CHARS

    #iterate through the reset characters
    for resetCharacter in MACHINE_LEG_RESET_CHARS:

        #send the reset character
        arduinoSerial.write(resetCharacter.encode())

#function to make the machine walk forward
def walkForward1Step(sleepTime = 0.75):

    #import global variables that are needed
    global arduinoSerial, MACHINE_LEG_MOVEMENT_CHARS

    #move the front and back legs backwards
    arduinoSerial.write('abcd'.encode())

    #wait for the motors to move
    time.sleep(sleepTime)

    #move the back legs forwards
    arduinoSerial.write('CD'.encode())

    #wait for the motors to move
    time.sleep(sleepTime)

    #move the front legs forwards
    arduinoSerial.write('AB'.encode())

    #wait for the motors to move
    time.sleep(sleepTime)

    #reset all the legs
    arduinoSerial.write('1234'.encode())

    #wait for the motors to move
    time.sleep(sleepTime)

#reset the legs
resetLegs()

#move forward once
walkForward1Step()

#reset the legs
resetLegs()