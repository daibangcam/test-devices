#include <Servo.h>

#define SERVO_PIN 12  // Chân D12 (Arduino) = Chân SpnEn (CNC Shield)

Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  myServo.write(0);
  delay(500);

  myServo.write(40);
  delay(500);
}
