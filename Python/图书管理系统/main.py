# 初始化数据
book = []
name = []
num = []
uid = ['admin']
psk = ['123456']

# 登录函数
def login():
    a = int(input("1: 登陆 2: 注册\n"))

    # 登陆
    if a == 1:
        uname = input("请输入用户名：")
        upsk = input("请输入密码：")
        if (uname in uid) and (upsk in psk):
            print("登陆成功")
            return 1
        else:
            print("登录失败")
            return 0
    # 注册
    else:
        uname = input("请输入你要注册的用户名:")
        upsk = input("请设置你的密码:")
        uid.append(uname)
        psk.append(upsk)
        print("注册成功")
        return 1

# 图书管理函数
def lib():
    print("欢迎登陆图书馆")
    func = ['1 查看图书', '2 图书入库', '3 图书更新', '4 图书出库', '0 退出']
    print("\n".join(func)) 
    a = int(input("请输入序号: "))

    if a == 1:
        print(book)
    elif a == 2:
        # 入库
        n = input("请输入书名: ")
        rmb = input("请输入价格: ")
        quantity = input("请输入库存: ")
        book.append({'name': n, 'price': rmb, 'quantity': quantity})
        print("图书入库成功！")
    elif a == 3:
        # 更新
        print(book)
        idx = int(input("请输入要更新的图书序号: "))
        if 0 <= idx < len(book):
            new_quantity = int(input("请输入新的库存数量: "))
            book[idx]['quantity'] = new_quantity
            print("图书更新成功！")
        else:
            print("不存在")
    elif a == 4:
        # 出库
        print(book)
        idx = int(input("请输入要出库的图书索引: "))
        if 0 <= idx < len(book):
            quantity_to_checkout = int(input("请输入出库数量: "))
            if book[idx]['quantity'] >= quantity_to_checkout:
                book[idx]['quantity'] -= quantity_to_checkout
                print(f"{quantity_to_checkout}本图书出库成功！")
            else:
                print("库存不足，出库失败。")
        else:
            print("无效的索引，请重新选择。")
    elif a == 0:
        # 退出
        return False

    return True  # 返回True继续循环

# 主程序
while True:
    if login():
        while lib():
            pass  # 什么都不做，只是为了保持循环