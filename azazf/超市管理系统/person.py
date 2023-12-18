import os
import csv
user_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv')
vip_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'vip.csv')
class Employ:
    def __init__(self, Ename, Epnum, Edress, Edegree):
        self.Ename = Ename #名字
        self.Epnum = Epnum#手机号
        self.Edress = Edress#地址
        self.Edegree = Edegree#职位

    def add_E():
        Ename = input('请输入员工姓名：')
        Epnum = input('请输入员工电话')
        Edress = input('请输入员工住址：')
        Edegree = input('请输入员工职位：')
        with open(user_csv_path, 'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([Ename,Epnum,Edress,Edegree])

    def del_E():
        Ename = input('请输入要删除的员工姓名：')
        with open(user_csv_path, 'r') as f:
            reader = csv.reader(f)
            lines = [row for row in reader if row[0] != Ename]
        with open(user_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerows(lines)
    def update_E():
        Ename = input("请输入要修改的员工名：")
        lines = []
        with open(user_csv_path, 'r') as f:
            reader = csv.reader(f)
            lines = [row for row in reader if row[0] != Ename]
        Epnum = input("请输入新的手机号：")
        Edress = input("请输入新的地址：")
        Edegree = input("请输入新的职位：")
        lines.append([Ename,Epnum,Edress,Edegree])
        with open(user_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerows(lines)
    def list_E():
        with open(user_csv_path, 'r') as f:
            reader = csv.reader(f)
            for row in reader:
                print(f"员工名字：{row[0]}，员工电话：{row[1]}，员工地址：{row[2]}，员工职位：{row[3]}")

class vip:
    def __init__(self, Vpnum, Vname, Vpoint):
        self.Vpnum = Vpnum
        self.Vname = Vname
        self.Vpoint = Vpoint

    def add_V():
        Vname = input("请输入持卡人姓名：")
        Vpoint = input("请输入本次增加积分：")
        Vpnum = input("请输入电话号码：")
        # 创建新用户
        new_user = vip(Vname, Vpnum, Vpoint)
        # 将新用户信息写入csv文件
        with open(vip_csv_path,'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([new_user.Vname, new_user.Vpnum, new_user.Vpoint])
        # 返回新用户
        return new_user

    def del_V():
        lines = []
        with open(vip_csv_path, 'r') as f:
            reader = csv.reader(f)
            lines = [row for row in reader]
        Vpnum = input("请输入要删除的卡号：")
        for row in lines:
            if row[1] == Vpnum:
                lines.remove(row)
        with open(vip_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
    def update_V():
        lines = []
        with open(vip_csv_path, 'r') as f:
            reader = csv.reader(f)
            lines = [row for row in reader]
        Vpnum = input("请输入要修改的卡号：")
        for row in lines:
            if row[1] == Vpnum:
                Vname = input("请输入修改后的姓名：")
                Vpoint = input("请输入修改后的积分：")
                row[0] = Vname
    def list_V():
        with open(vip_csv_path, 'r') as f:
            reader = csv.reader(f)
            for row in reader:
                print(f"会员编号：{row[0]}，会员名字：{row[1]}，会员积分：{row[2]}")
