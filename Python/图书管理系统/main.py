import login
import book as book
import os
import csv 
# 检查文件存在
def check_file_exists():
    # 获取当前文件路径
    user_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv')
    books_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'books.csv')

    # 如果用户csv文件不存在，则创建
    if not os.path.isfile(user_csv_path):
        with open(user_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["UID", "PSK", "Name", "cid", "Phone"])

    # 如果书籍csv文件不存在，则创建
    if not os.path.isfile(books_csv_path):
        with open(books_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["Title", "Author", "Num"])

def main():
    # 检查并初始化用户和书籍信息
    check_file_exists()    
    # 定义主函数
    while True:
        print(
"""
快和坤坤一起来图书馆学习吧！
    ⠀⠀⠀⠀⠰⢷⢿⠄
    ⠀⠀⠀⠀⠀⣼⣷⣄
    ⠀⠀⣤⣿⣇⣿⣿⣧⣿⡄
    ⢴⠾⠋⠀⠀⠻⣿⣷⣿⣿⡀
    🏀⠀⢀⣿⣿⡿⢿⠈⣿
    ⠀⠀⠀⢠⣿⡿⠁⠀⡊⠀⠙
    ⠀⠀⠀⢿⣿⠀⠀⠹⣿   
    ⠀⠀⠀⠀⠹⣷⡀⠀⣿⡄
    ⠀⠀⠀⠀⣀⣼⣿⠀⢈⣧
🏀登录 🏀🏀注册 🏀🏀🏀退出
"""
              )
        choice = input("请选择：")

        if choice == '1':
            user_type = login.User.login()
            if user_type == 'user':
                print("登录成功！")
                while True:
                    print("1. 列出所有的书")
                    print("2. 借书")
                    print("3. 还书")
                    print("4. 退出")
                    choice = input("请选择：")

                    if choice == '1':
                        book.list_books()
                    elif choice == '2':
                        book.borrow_book()
                    elif choice == '3':
                        book.return_book()
                    elif choice == '4':
                        break
            elif user_type == 'admin':
                print("管理员登录成功！")
                while True:
                    print("1. 列出所有的书")
                    print("2. 新增图书")
                    print("3. 修改图书")
                    print("4. 删除图书")
                    print("5. 退出")
                    choice = input("请选择：")

                    if choice == '1':
                        book.list_books()
                    elif choice == '2':
                        book.add_book()
                    elif choice == '3':
                        book.update_book()
                    elif choice == '4':
                        book.delete_book()
                    elif choice == '5':
                        break
            else:
                print("登录失败！")
        elif choice == '2':
            user = login.User.register()
        elif choice == '3':
            break

if __name__ == "__main__":
    main()