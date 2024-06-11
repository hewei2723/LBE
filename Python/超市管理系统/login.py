class User:
    # 初始化函数，用于初始化用户对象
    def __init__(self, username, password):
        # 用户名
        self.username = username
        # 密码
        self.password = password
    # 定义登录函数
    def login():
        # 输入用户名
        username = input("请输入用户名：")
        # 输入密码
        password = input("请输入密码：")

        # 如果用户名和密码正确，返回admin
        if username == '1' and password == '1':
            return 'success'
        return None