import csv
from datetime import datetime

time_now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

def write_csv(data_to_write):
    with open("data.csv", mode="a", newline="", encoding="utf-8-sig") as file:
        writer = csv.writer(file)
        writer.writerow(data_to_write)

    print(f"Ghi nhận dữ liệu: {data_to_write}")


def read_csv():
    with open("data.csv", mode="r", encoding="utf-8-sig") as file:
        reader = csv.reader(file)
        for row in reader:
            print(row)

if __name__ == "__main__":
    data1 = input(str("Nhập data 1: "))
    data2 = input(str("Nhập data 2: "))
    data3 = input(str("Nhập data 3: "))

    data = [data1, data2, data3]

    write_csv(data)
    read_csv()