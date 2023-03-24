import serial
import time

arduino = serial.Serial(port='COM9', baudrate=115200, timeout=.1)
time.sleep(2)


def get_action_command(action, motor, direction, steps):
    return f"{action}:{motor}:{direction}:{steps}:;"


while True:
    ctrl = str(input())
    ctrl = ctrl.split(" ")
    # if ctrl[0] == '2':
    #     break
    i = 0
    if ctrl[0] == "w":
        while i < int(ctrl[1]):
            i += 1
            print(ctrl[1])
            arduino.write(b'1')
            data = arduino.readline()
    if ctrl[0] == "s":
        while i < int(ctrl[1]):
            i += 1
            arduino.write(b'0')
            data = arduino.readline()
