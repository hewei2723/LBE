import login
import book_operations
import os
import csv 
def check_file_exists():
    user_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv')
    books_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'books.csv')

    if not os.path.isfile(user_csv_path):
        with open(user_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["用户名", "密码", "姓名", "班级", "电话号码"])

    if not os.path.isfile(books_csv_path):
        with open(books_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["书名", "作者", "数量"])

def main():
    # 检查并初始化用户和书籍信息
    check_file_exists()
    

    while True:
        print("1. 登录")
        print("2. 注册")
        print("3. 退出")
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
                        book_operations.list_books()
                    elif choice == '2':
                        book_operations.borrow_book()
                    elif choice == '3':
                        book_operations.return_book()
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
                        book_operations.list_books()
                    elif choice == '2':
                        book_operations.add_book()
                    elif choice == '3':
                        book_operations.update_book()
                    elif choice == '4':
                        book_operations.delete_book()
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
