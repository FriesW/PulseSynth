import serial
import socket

p = input('Comport: ')

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
def bang():
    sock.sendto(b' ', ('127.0.0.1', 3344))

    
high = False

with serial.Serial(p, 9600, timeout=5) as ser:
    ser.readline()
    while True:
        v = int(ser.readline().decode().strip())
        if( v > 750 and not high):
            bang()
            high = True
        if( v < 650 and high):
            high = False