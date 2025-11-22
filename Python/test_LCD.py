from signal import signal, SIGTERM, SIGHUP, pause
from rpi_lcd import LCD

# Địa chỉ I2C cho hai màn hình LCD (thay đổi địa chỉ phù hợp với các màn hình của bạn)
I2C_ADDR_LCD1 = 0x27
I2C_ADDR_LCD2 = 0x25


def lcd_display(I2C_ADDR_LCD1, txt1_line_1, txt1_line_2, I2C_ADDR_LCD2, txt2_line_1, txt2_line_2):
    lcd1 = LCD(address=I2C_ADDR_LCD1)
    lcd2 = LCD(address=I2C_ADDR_LCD2)

    def safe_exit(signum, frame):
        lcd1.clear()
        lcd2.clear()
        exit(1)
        # Khởi tạo hai đối tượng LCD với địa chỉ I2C khác nhau

    try:
        # Đăng ký hàm safe_exit để xử lý các tín hiệu SIGTERM và SIGHUP
        signal(SIGTERM, safe_exit)
        signal(SIGHUP, safe_exit)
        # Hiển thị văn bản trên màn hình LCD
        lcd1.text(txt1_line_1, 1)
        lcd1.text(txt1_line_2, 2)
        lcd2.text(txt2_line_1, 1)
        lcd2.text(txt2_line_2, 2)
        # Đợi cho đến khi nhận được tín hiệu kết thúc
        pause()
    except KeyboardInterrupt:
        pass
    finally:
        # Xóa màn hình LCD khi chương trình kết thúc
        lcd1.clear()
        lcd2.clear()


lcd_display(I2C_ADDR_LCD1, '12345', '67890', I2C_ADDR_LCD2, 'abcde', 'fghbn')