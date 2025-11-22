#include <SoftwareSerial.h>

SoftwareSerial sim800(5, 6);  // RX, TX cho giao tiếp với SIM800C
const int buttonPin = 4;     // Chân A7 cho nút nhấn hoặc cảm biến

void setup() {
  // Khởi tạo Serial để giao tiếp với máy tính
  Serial.begin(9600);

  // Khởi tạo giao tiếp với SIM800C
  sim800.begin(9600);

  // Khởi tạo chân 4 làm input với nội trở kéo lên
  pinMode(buttonPin, INPUT_PULLUP);

  // Kiểm tra kết nối với SIM800C bằng lệnh AT
  sim800.println("AT");
  delay(1000);
  if (sim800.available()) {
    Serial.println(sim800.readString());
  }

  Serial.println("Hệ thống đã sẵn sàng.");
}

void loop() {
  // Kiểm tra trạng thái nút nhấn hoặc cảm biến trên chân A7
  if (digitalRead(buttonPin) == HIGH) {  // Nút được nhấn khi tín hiệu là HIGH do có nội trở kéo lên
    // Khi nút nhấn được kích hoạt, gửi tin nhắn cảnh báo
    sendSMS();
    // Đợi 5 giây trước khi thực hiện cuộc gọi
    delay(5000);
    
    // Gọi điện thoại cảnh báo
    callPhone();
      delay(20000);
  }

  delay(1000);  // Đợi 1 giây trước khi kiểm tra lại nút nhấn
}

void sendSMS() {
  // Đặt chế độ gửi SMS
  sim800.println("AT+CMGF=1");  // Chế độ gửi tin nhắn văn bản
  delay(1000);
  Serial.println("Chế độ SMS đã được thiết lập");

  // Gửi số điện thoại để nhắn tin
  sim800.println("AT+CMGS=\"+84834429939\""); 
  delay(1000);

  // Gửi nội dung tin nhắn
  sim800.print("CANH BAO: CO CHAY,CO CHAY!!!!");  // Nội dung tin nhắn
  delay(1000);

  // Gửi mã kết thúc tin nhắn
  sim800.write(26);  // Mã kết thúc (Ctrl+Z hoặc 26)
  delay(1000);

  Serial.println("Tin nhắn đã được gửi!");
}

void callPhone() {
  // Gửi lệnh gọi điện thoại đến số chỉ định
  sim800.println("ATD+84834429939;");  // Thay +84123456789 bằng số điện thoại bạn muốn gọi
  delay(1000);
  Serial.println("Đang gọi điện...");

  // Giữ cuộc gọi trong khoảng 30 giây rồi ngắt
  delay(30000);
  
  // Lệnh ngắt cuộc gọi
  sim800.println("ATH");
  delay(1000);
  Serial.println("Cuộc gọi đã kết thúc.");
}
