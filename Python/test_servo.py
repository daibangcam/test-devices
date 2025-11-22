import RPi.GPIO as GPIO
from time import sleep

ser = 11 # Chân 19 5 3

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(ser, GPIO.OUT)

pwm=GPIO.PWM(ser, 50)
pwm.start(2.5)

def SetAngle(angle):
    duty = 2 + (angle / 18)
    GPIO.output(ser, True)
    pwm.ChangeDutyCycle(duty)
    sleep(0.03)
    GPIO.output(ser, False)
    pwm.ChangeDutyCycle(0)

try:
    while 1:
#         SetAngle(5)
#         sleep(1)
#         SetAngle(45)
#         sleep(1)
        pwm.ChangeDutyCycle(2.5)
        sleep(1)
        pwm.ChangeDutyCycle(5.5)
        sleep(1)
#     SetAngle(0)
except KeyboardInterrupt:
    pass
finally:
    pwm.stop()
    GPIO.cleanup()
