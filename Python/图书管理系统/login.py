import csv
import os
class User:
    # 初始化函数，用于初始化用户对象
    def __init__(self, username, password, name, class_name, phone_number):
        # 用户名
        self.username = username
        # 密码
        self.password = password
        # 姓名
        self.name = name
        # 班级名
        self.class_name = class_name
        # 手机号
        # 初始化类
        self.phone_number = phone_number

   # 定义注册函数，用于注册新用户
    def register():
        # 获取用户输入的参数
        username = input("请输入用户名：")
        password = input("请输入密码：")
        name = input("请输入姓名：")
        class_name = input("请输入班级：")
        phone_number = input("请输入电话号码：")
        # 创建新用户
        new_user = User(username, password, name, class_name, phone_number)

        # 将新用户信息写入csv文件
        with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv'),'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([new_user.username, new_user.password, new_user.name, new_user.class_name, new_user.phone_number])
        # 返回新用户
        return new_user

    # 定义登录函数
    def login():
        # 输入用户名
        username = input("请输入用户名：")
        # 输入密码
        password = input("请输入密码：")

        # 如果用户名和密码正确，返回admin
        if username == 'admin' and password == '123456':
            return 'admin'

        # 打开users.csv文件，读取文件内容
        with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv'), 'r') as f:
            reader = csv.reader(f)
            # 遍历文件内容，如果用户名和密码正确，返回user
            for row in reader:
                if row[0] == username and row[1] == password:
                    return 'user'
        # 如果用户名和密码不正确，返回None
        return None