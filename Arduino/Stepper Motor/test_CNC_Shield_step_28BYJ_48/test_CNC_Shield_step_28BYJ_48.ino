// Động cơ nối vào trục X của CNC shield
// Nối dây động cơ: ĐỎ = ko kết nối; CAM = 1B; VÀNG = 2A; HÒNG = 1A; XANH = 2B.
// Dây từ trên xuống: xanh - vàng - hồng - cam
const int X_Step = 2;
const int X_Dir = 5;
const int Enable = 8;

void setup() {
  pinMode(X_Step, OUTPUT);    
  pinMode(X_Dir, OUTPUT);     
  pinMode(Enable, OUTPUT);

  digitalWrite(Enable, LOW); // LOW = bật, HIGH = tắt
}

void loop() {
  digitalWrite(X_Dir,HIGH);             // High Signal to rotat the stepper motor clockwise
  for(int x=0; x<400; x++)                // Create a pulse Step loop to rotate one revolution (2048 step for 28BYJ / 200 step for NEMA 17)
    {digitalWrite(X_Step,HIGH);          // High Signal for the pulse
    delayMicroseconds(500);               // Waiting time between each pulse
    digitalWrite(X_Step,LOW);           // LOW Signal for the pulse
    delayMicroseconds(500);               // Waiting time between each pulse
    }

  delay(1000);                            // Waiting time between each revolution

  digitalWrite(X_Dir,LOW);             // LOW Signal to rotat the stepper motor Counter clockwise
  for(int x=0; x<400; x++)
    {digitalWrite(X_Step,HIGH);
    delayMicroseconds(500);
    digitalWrite(X_Step,LOW);
    delayMicroseconds(500);
    }
  
  delay(1000);                           // Waiting time between each revolution
}