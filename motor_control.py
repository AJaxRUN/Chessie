import serial, time

arduino = serial.Serial(port='COM7', baudrate=115200, timeout=.1)
i = 0
while i < 3000:
    # ctrl = input()
    # if ctrl == 2:
    #     break
    i += 1
    arduino.flushOutput();
    arduino.write("2".encode())
    time.sleep(0.5)
    data = arduino.readline()
    print(data)
    # time.sleep(0.05)
    

# arduino.write("2".encode())