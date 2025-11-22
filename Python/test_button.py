import RPi.GPIO as GPIO
import time

# GPIO setup
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

# Define GPIO pins for the buttons
button1_pin = 10
button2_pin = 9
button3_pin = 11

# Set up buttons as inputs
GPIO.setup(button1_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(button2_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(button3_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# Callback functions for button presses
def button1_callback(channel):
    print("1")

def button2_callback(channel):
    print("2")

def button3_callback(channel):
    print("3")

# Attach event detection to buttons with debouncing
GPIO.add_event_detect(button1_pin, GPIO.FALLING, callback=button1_callback, bouncetime=300)
GPIO.add_event_detect(button2_pin, GPIO.FALLING, callback=button2_callback, bouncetime=300)
GPIO.add_event_detect(button3_pin, GPIO.FALLING, callback=button3_callback, bouncetime=300)

try:
    # Keep the script running to detect button presses
    print("Running  while True loop...")
    while True:
        time.sleep(0.1)  # Sleep to reduce CPU usage

except KeyboardInterrupt:
    print("Exiting...")

finally:
    GPIO.cleanup()  # Clean up GPIO settings
