from csv import writer
import time

log_path = '../log.csv'
log_date = time.strftime("%d-%m-%Y")
log_time = time.strftime("%H:%M:%S", time.localtime())

data = [
    ["","","",""],
    ["Date","Time", "Object", "Status"],
    [f"{log_date}", f"{log_time}", "System", "Activate"]
]

with open(log_path, "a", encoding="utf-8") as file:
    for row in data:
        file.write(','.join(map(str, row)) + '\n')
    file.close()


while 1:
    string_x = input("Nhập id: ")
    string_y = input("Nhập trang thái: ")

    data_write = [f"{log_date}", f"{log_time}", ]

    data_write.extend([string_x, string_y])
    print(data_write)

    with open(log_path, "a", encoding="utf-8") as wfile:
        write_data = writer(wfile)
        write_data.writerow(data_write)
        wfile.close()