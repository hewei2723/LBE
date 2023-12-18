import os
import csv
s_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'items.csv')
class items:
    def __init__(self,Sname,Sid,Snum,Spri):
        self.Sname = Sname
        self.Sid = Sid
        self.Snum = Snum
        self.Spri = Spri
    def add_S():  # 增加商品
        Sname = input("请输入商品名称：")
        Sid = input("请输入商品编号：")
        Snum = int(input("请输入商品数量："))
        Spri = int(input("请输入商品价格："))
        with open(s_csv_path, 'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([Sname, Sid, Snum, Spri])

    def del_S():  # 删除商品
        Sid = input("请输入要删除的商品编号：")
        lines = []
        with open(s_csv_path, 'r') as f:
            reader = csv.reader(f)
            lines = [row for row in reader if row[1] != Sid]
        with open(s_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerows(lines)

    def rep_S():  # 库存商品
        Sid = input("请输入要查询的商品编号：")
        with open(s_csv_path, 'r') as f:
            reader = csv.reader(f)
            for row in reader:
                if row[1] == Sid:
                    print(f"商品编号：{row[1]}，商品名称：{row[0]}，商品数量：{row[2]}，商品价格：{row[3]}")
                    return

    def list_S():  # 列出库存
        with open(s_csv_path, 'r') as f:
            reader = csv.reader(f)
            for row in reader:
                print(f"商品编号：{row[1]}，商品名称：{row[0]}，商品数量：{row[2]}，商品价格：{row[3]}")

    def update_S():  # 修改商品
        Sid = input("请输入要修改的商品编号：")
        Sname = input("请输入新的商品名称：")
        Snum = int(input("请输入新的商品数量："))
        Spri = int(input("请输入新的商品价格："))
        lines = []
        with open(s_csv_path, 'r') as f:
            reader = csv.reader(f)
            lines = [row for row in reader]
        for row in lines:
            if row[1] == Sid:
                row[0] = Sname
                row[2] = Snum
                row[3] = Spri
        with open(s_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerows(lines)
