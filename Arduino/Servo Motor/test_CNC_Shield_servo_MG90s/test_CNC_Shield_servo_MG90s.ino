#include <Servo.h>

#define SERVO_PIN 12  // Chân D12 (Arduino) = Chân SpnEn (CNC Shield)

Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  myServo.write(180);
  delay(500);

  myServo.write(100);
  delay(500);
}
