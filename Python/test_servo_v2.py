import RPi.GPIO as GPIO
from time import sleep

ser = 19 # Chân 19 5 3

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(ser, GPIO.OUT)

pwm = GPIO.PWM(ser, 50)
pwm.start(0)

def control_servo(angle):
    if angle < 0:
        angle = 0
    elif angle > 180:
        angle = 180
    
    duty_cycle = 2.5 + (angle / 180) * 10
    pwm.ChangeDutyCycle(duty_cycle)
    sleep(0.6)
    
    
def main():
    try:
        while 1:
            control_servo(5)
#             sleep(1)
            control_servo(55)
#             sleep(1)
    except KeyboardInterrupt:
        pass
    finally:
        pwm.stop()
        GPIO.cleanup()
        
if __name__ == "__main__":
    main()
            
