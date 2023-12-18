import login
import os
import csv 
import person
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
                        print("1. 增加员工信息")
                        print("2. 修改员工信息")
                        print("3. 删除员工信息")
                        print("4. 列出所有员工信息")
                        menu = input("请选择：")
                        if menu == '1':
                            person.Employ.add_E()
                        elif menu == '2':
                            pass
                        elif menu == '3':
                            pass
                        elif menu == '4':
                            pass
                    elif choice == '2':
                        print("1. 商品入库")
                        print("2. 商品出库")
                        print("3. 商品库存")
                        print("4. 列出所有商品")
                        menu = input("请选择：")
                        if menu == '1':
                            pass
                        elif menu == '2':
                            pass
                        elif menu == '3':
                            pass
                        elif menu == '4':
                            pass
                    elif choice == '3':
                        print("1. 增加会员信息")
                        print("2. 删除会员信息")
                        print("3. 修改会员信息")
                        print("4. 列出所有会员信息")
                        menu = input("请选择：")
                        if menu == '1':
                            pass
                        elif menu == '2':
                            pass
                        elif menu == '3':
                            pass
                        elif menu == '4':
                            pass
                    elif choice == '4':
                        break
            else:
                print("登录失败！")
        elif choice == '2':
            break
if __name__ == "__main__":
    main()