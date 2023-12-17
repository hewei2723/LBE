import csv
import os
class User:
    def __init__(self, username, password, name, class_name, phone_number):
        self.username = username
        self.password = password
        self.name = name
        self.class_name = class_name
        self.phone_number = phone_number

    @staticmethod
    def register():
        username = input("请输入用户名：")
        password = input("请输入密码：")
        name = input("请输入姓名：")
        class_name = input("请输入班级：")
        phone_number = input("请输入电话号码：")
        new_user = User(username, password, name, class_name, phone_number)

        with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv'),'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([new_user.username, new_user.password, new_user.name, new_user.class_name, new_user.phone_number])
        return new_user

    @staticmethod
    def login():
        username = input("请输入用户名：")
        password = input("请输入密码：")

        if username == 'admin' and password == '123456':
            return 'admin'

        with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv'), 'r') as f:
            reader = csv.reader(f)
            for row in reader:
                if row[0] == username and row[1] == password:
                    return 'user'
        return None
