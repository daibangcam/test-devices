#include <Servo.h>
//    Servo       CNC Shield
//     5V             5V 
//     GND            GND
//    Signal         SpnEn
#define servo_pin 12
#define en          8

int servo_open = 0;
int servo_close = 60;

Servo myservo; // Khai báo tên động cơ servo (tay gắp)

int delay_time = 500;

void setup() 
{
  ///////////////////////
  pinMode(en, OUTPUT);
  digitalWrite(en, LOW);

  // Khai báo chân điều khiển động cơ servo
  myservo.attach(servo_pin);
}

void loop() 
{
  // calib servo
  // myservo.write(0);
  // delay(delay_time);
  //
  myservo.write(servo_close);
  delay(delay_time);
  myservo.write(servo_open);
  delay(delay_time);
}
