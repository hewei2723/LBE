import login
import os
import csv 
# 检查文件存在
def check_file_exists():
    # 获取当前文件路径
    user_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'users.csv')
    s_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'items.csv')
    vip_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'vip.csv')


    # 如果用户csv文件不存在，则创建
    if not os.path.isfile(user_csv_path):
        with open(user_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["Ename", "Epnum", "Edress", "Edegree", "Phone"])

    # 如果商品csv文件不存在，则创建
    if not os.path.isfile(s_csv_path):
        with open(s_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["Sname", "Sid", "Snum","Spri"])

    # 如果vip文件不存在，则创建
    if not os.path.isfile(vip_csv_path):
        with open(vip_csv_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["Vname", "Vid", "Vpoint"])
def main():
    check_file_exists()    
    while True:
        print(
"""
超市管理
1登陆 2退出
"""
              )
        choice = input("请选择：")

        if choice == '1':
            user_type = login.User.login()
            if user_type == 'success':
                print("登录成功！")
                while True:
                    print("1. 员工管理")
                    print("2. 商品管理")
                    print("3. 会员管理")
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
            else:
                print("登录失败！")
        elif choice == '2':
            break
if __name__ == "__main__":
    main()