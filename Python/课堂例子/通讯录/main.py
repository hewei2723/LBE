# 定义一个列表保存联系人信息
frilist = [
    ["王健林", "13555555555"],
    ["马云", "13666666668"],
    ["马化腾", "13888888888"],
    ["刘强东", "13777777777"]
]

# 定义一个类
class 面向对象编程.own.Person:
    def __init__(self, name, telnum):
        self.name = name
        self.telnum = telnum

    # 查询显示
    def saysome(self):
        print("你朋友%s的电话是: %s" % (self.name, frilist[snu][1]))

    # 添加
    def addperson(self, name, telnum):
        self.name = name
        self.telnum = telnum
        newlist = [self.name, self.telnum]
        frilist.append(newlist)
        print("Successful!")

    # 删除
    def delperson(self, name):
        self.name = name
        del frilist[snu]
        print("Successful DEL")

    # 修改
    def alterperson(self, name, telnum):
        self.name = name
        frilist[snu][1] = telnum
        print("Successful update!")

# 本程序是一个简易的通讯录程序，请选择以下服务:
while True:
    print("1. 添加朋友")
    print("2. 删除朋友")
    print("3. 修改联系电话")
    print("4. 查找朋友")
    print("5. 显示通讯录列表")
    print("0. 退出程序")

    choice = input("请选择服务[1,2,3,4,5,0]: ")

    if choice == "1":
        sname = input("请输入姓名-->")
        telnum = input("请输入联系电话-->")
        p = 面向对象编程.own.Person(sname, telnum)
        p.addperson(sname, telnum)

    elif choice == "2":
        sname = input("请输入姓名-->")
        p = 面向对象编程.own.Person(sname, "")
        p.delperson(sname)

    elif choice == "3":
        sname = input("请输入姓名-->")
        telnum = input("请输入新的联系电话-->")
        p = 面向对象编程.own.Person(sname, telnum)
        p.alterperson(sname, telnum)

    elif choice == "4":
        sname = input("请输入姓名-->")
        namelist = [i[0] for i in frilist]
        flag = False
        for strname in namelist:
            if sname == strname:
                flag = True
                break
        if flag:
            snu = namelist.index(sname)
            p = 面向对象编程.own.Person(sname, "")
            p.saysome()
        else:
            print("Not in it")

    elif choice == "5":
        print(frilist)

    elif choice == "0":
        print("再见！")
        exit()

    else:
        print("请输入列表中的号码！")