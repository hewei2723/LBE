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
                        print("1增加员工信息")
                        print("2修改员工信息")
                        print("删除员工信息")
                        print("列出所有员工信息")
                        menu = input("请选择：")
                        if menu == '1':
                            print("增加员工信息")
                        elif menu == '2':
                            print("修改员工信息")
                        elif menu == '3':
                            print("删除员工信息")
                        elif menu == '4':
                            print("列出所有员工信息")
                    elif choice == '2':
                        print("商品入库")
                        print("商品出库")
                        print("商品库存")
                        print("列出所有商品")
                        menu = input("请选择：")
                        if menu == '1':
                            print("商品入库")
                        elif menu == '2':
                            print("商品出库")
                        elif menu == '3':
                            print("商品库存")
                        elif menu == '4':
                            print("列出所有商品")
                    elif choice == '3':
                        print("增加会员信息")
                        print("删除会员信息")
                        print("修改会员信息")
                        print("列出所有会员信息")
                        menu = input("请选择：")
                        if menu == '1':
                            print("增加会员信息")
                        elif menu == '2':
                            print("删除会员信息")
                        elif menu == '3':
                            print("修改会员信息")
                        elif menu == '4':
                            print("列出所有会员信息")
                    elif choice == '4':
                        break
            else:
                print("登录失败！")
        elif choice == '2':
            break
if __name__ == "__main__":
    main()