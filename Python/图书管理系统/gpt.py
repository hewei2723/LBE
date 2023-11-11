# 用户信息存储
users = [{"username": "user1", "password": "pass1"}, {"username": "user2", "password": "pass2"}]

# 图书库存
books = [{"title": "Book1", "author": "Author1", "quantity": 10},
         {"title": "Book2", "author": "Author2", "quantity": 15}]

# 登录函数
def login():
    username = input("请输入用户名: ")
    password = input("请输入密码: ")

    for user in users:
        if user["username"] == username and user["password"] == password:
            print("登录成功！")
            return True

    print("用户名或密码错误，请重新登录。")
    return False

# 注册函数
def register():
    username = input("请输入用户名: ")

    for user in users:
        if user["username"] == username:
            print("用户名已存在，请重新注册。")
            return

    password = input("请输入密码: ")
    users.append({"username": username, "password": password})
    print("注册成功！")

# 查询图书函数
def query_books():
    print("图书库存:")
    for book in books:
        print(f"标题: {book['title']}, 作者: {book['author']}, 数量: {book['quantity']}")

# 图书入库函数
def add_book():
    title = input("请输入图书标题: ")
    author = input("请输入图书作者: ")
    quantity = int(input("请输入入库数量: "))

    for book in books:
        if book["title"] == title and book["author"] == author:
            book["quantity"] += quantity
            print(f"{quantity}本图书入库成功！")
            return

    books.append({"title": title, "author": author, "quantity": quantity})
    print(f"{quantity}本新图书入库成功！")
# 图书更新函数
def update_book():
    title = input("请输入要更新的图书标题: ")
    author = input("请输入要更新的图书作者: ")
    new_quantity = int(input("请输入新的图书数量: "))

    for book in books:
        if book["title"] == title and book["author"] == author:
            book["quantity"] = new_quantity
            print("图书更新成功！")
            return

    print("未找到指定的图书，请检查输入。")

# 图书出库函数
def checkout_book():
    title = input("请输入要出库的图书标题: ")
    author = input("请输入要出库的图书作者: ")
    quantity_to_checkout = int(input("请输入出库数量: "))

    for book in books:
        if book["title"] == title and book["author"] == author:
            if book["quantity"] >= quantity_to_checkout:
                book["quantity"] -= quantity_to_checkout
                print(f"{quantity_to_checkout}本图书出库成功！")
                return
            else:
                print("库存不足，出库失败。")
                return

    print("未找到指定的图书，请检查输入。")

# 主程序
def main():
    while True:
        print("\n1. 登录\n2. 注册\n3. 退出")
        choice = input("请选择操作: ")

        if choice == "1":
            if login():
                while True:
                    print("\n1. 查询图书\n2. 图书入库\n3. 图书更新\n4. 图书出库\n5. 退出")
                    operation = input("请选择操作: ")

                    if operation == "1":
                        query_books()
                    elif operation == "2":
                        add_book()
                    elif operation == "3":
                        update_book()
                    elif operation == "4":
                        checkout_book()
                    elif operation == "5":
                        break
                    else:
                        print("无效的操作，请重新选择。")
        elif choice == "2":
            register()
        elif choice == "3":
            print("谢谢使用，再见！")
            break
        else:
            print("无效的操作，请重新选择。")

#防止系统关闭
if __name__ == "__main__":
    main()