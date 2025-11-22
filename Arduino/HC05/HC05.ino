#include <SoftwareSerial.h>
SoftwareSerial HBluetooth(10, 11); // RX | TX

/*
AT
AT+NAME="YourDeviceName"
AT+PSWD="YourDevicePassword"
AT+UART=9600,0,0
*/

void setup()
{
  //Baud Rate for command Mode.
  Serial.begin(9600); HBluetooth.begin(38400);   
  //Serial.println("Enter AT commands!");
}

void loop()
{
  // Feed any data from bluetooth to Terminal.
  if (HBluetooth.available())
    Serial.write(HBluetooth.read());
    // Feed all data from termial to bluetooth
  if (Serial.available())
    HBluetooth.write(Serial.read());
}