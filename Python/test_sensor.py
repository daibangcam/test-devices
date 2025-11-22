import RPi.GPIO as GPIO
from time import sleep

sensor = 21       # 29(cam), 21, 23, 11, 

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD) 
GPIO.setup(sensor, GPIO.IN)

try:
    while 1:
        print(GPIO.input(sensor))
        sleep(1)
        
except KeyboardInterrupt:
    GPIO.cleanup()