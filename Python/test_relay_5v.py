import RPi.GPIO as GPIO
from time import sleep

relay = 16

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

GPIO.setup(relay, GPIO.OUT)

try:
    while 1:
        GPIO.output(relay, GPIO.HIGH)
        sleep(5)
        GPIO.output(relay, GPIO.LOW)
        sleep(5)
except KeyboardInterrupt:
    GPIO.cleanup()
    pass