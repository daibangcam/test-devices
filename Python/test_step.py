#######################################
# Copyright (c) 2021 Maker Portal LLC
# Author: Joshua Hrisko
#######################################
#
# NEMA 17 (17HS4023) Raspberry Pi Tests
# --- rotating the NEMA 17 to test
# --- wiring and motor functionality
#
#
#######################################
#
import RPi.GPIO as GPIO
from RpiMotorLib import RpiMotorLib
import time

################################
# RPi and Motor Pre-allocations
################################
#
#define GPIO pins
direction = 27  # Direction (DIR) GPIO Pin
step = 17       # Step GPIO Pin
EN_pin = 18     # Enable pin (LOW to enable)

# Declare an instance of class pass GPIO pins numbers and the motor type
mymotortest = RpiMotorLib.A4988Nema(direction, step, (21, 21, 21), "DRV8825")
GPIO.setup(EN_pin, GPIO.OUT)  # Set enable pin as output

def accelerate_motor(steps, min_delay, max_delay, accel_steps, direction):
    # Enable motor
    GPIO.output(EN_pin, GPIO.LOW) 

    # Acceleration phase
    for i in range(accel_steps):
        delay = max_delay - ((max_delay - min_delay) * (i / accel_steps))
        mymotortest.motor_go(direction, "Full", 1, delay, False, 0)
        
    # Constant speed phase
    for i in range(steps - 2 * accel_steps):
        mymotortest.motor_go(direction, "Full", 1, min_delay, False, 0)
    
    # Deceleration phase
    for i in range(accel_steps):
        delay = min_delay + ((max_delay - min_delay) * (i / accel_steps))
        mymotortest.motor_go(direction, "Full", 1, delay, False, 0)

    # Disable motor
    GPIO.output(EN_pin, GPIO.HIGH) 

# Example usage
steps = 20000
min_delay = 0.0005
max_delay = 0.0001
accel_steps = 5000
direction = False  # False for Counter-Clockwise, True for Clockwise

accelerate_motor(steps, min_delay, max_delay, accel_steps, direction)

GPIO.cleanup() # Clear GPIO allocations after run
