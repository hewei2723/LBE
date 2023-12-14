class stu:
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score

class sms:
    def __init__(self):
        self.students = []

    def add_stu(self, name, age, score):
        new_stu = stu(name, age, score)
        self.students.append(new_stu)

    def find_stu(self, name):
        for student in self.students:
            if student.name == name:
                print("姓名：%s 年龄：%s 成绩：%s" % (student.name, student.age, student.score))
                return
        print("没有该学生")

    def show_all(self):
        if not self.students:
            print("学生列表为空")
            return
        for student in self.students:
            print("姓名：%s 年龄：%s 成绩：%s" % (student.name, student.age, student.score))

# 创建学生管理系统对象
sms_obj = sms()

while True:
    print("1 添加 2 查询 3 显示所有 4 退出")
    menu = input("请输入菜单：")

    if menu == "1":
        while True:
            name = input("请输入姓名（输入q退出）：")
            if name == "q":
                break
            age = input("请输入年龄：")
            score = input("请输入成绩：")
            sms_obj.add_stu(name, age, score)
    elif menu == "2":
        name = input("请输入姓名：")
        sms_obj.find_stu(name)
    elif menu == "3":
        sms_obj.show_all()
    elif menu == "4":
        print("退出")
        break
    else:
        print("输入错误")
