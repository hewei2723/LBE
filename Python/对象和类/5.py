class SchoolMember:
    # 定义一个Person类，构造函数接收三个参数name, age, gender
    def __init__(self, name, age, gender):
        self.name = name
        self.age = ages
        self.gender = gender
# 定义一个show方法，用于显示Person类的属性
    def show(self):
        pass
# 定义Teacher类，继承自SchoolMember类
class Teacher(SchoolMember):
    # 初始化函数，传入参数：姓名，年龄，性别，酬金，课程
    def __init__(self, name, age, gender, salary, course):
        # 调用父类的初始化函数，传入参数：姓名，年龄，性别
        super().__init__(name, age, gender)
        # 给实例属性赋值
        self.salary = salary
        self.course = course
    # 定义show函数，打印教师信息
    def show(self):
        print(f"教师信息 - 姓名: {self.name}, 年龄: {self.age}, 性别: {self.gender}, 酬金: {self.salary}, 课程: {self.course}")
    # 定义teach函数，打印教师正在教授课程的信息
    def teach(self):
        print(f"{self.name} 正在教授 {self.course} 课程")
class Student(SchoolMember):
   # 初始化函数，传入参数name, age, gender, student_id, tuition, course
    def __init__(self, name, age, gender, student_id, tuition, course):
        super().__init__(name, age, gender)
        self.student_id = student_id
        self.tuition = tuition
        self.course = course
    # 打印学生信息
    def show(self):
        print(f"学生信息 - 姓名: {self.name}, 年龄: {self.age}, 性别: {self.gender}, 学生ID: {self.student_id}, 学费: {self.tuition}, 课程: {self.course}")
    # 打印交学费信息
    def pay_tuition(self):
        print(f"{self.name} 缴纳了学费 {self.tuition}")
class School:
    # 初始化函数，传入名称和地址
    def __init__(self, name, address):
        self.name = name
        self.address = address
        self.teachers = []
        self.students = []
# 注册学生函数，传入学生对象
    def enroll(self, student):
        self.students.append(student)
        print(f"{student.name} 已成功注册到 {self.name}")
# 雇佣教师函数，传入教师对象
    def hire(self, teacher):
        self.teachers.append(teacher)
        print(f"{teacher.name} 已成功加入 {self.name} 的教师队伍")
# 打印学校信息函数
    def information(self):
        # 打印学校信息
        print(f"\n学校信息 - 名称: {self.name}, 地址: {self.address}")
        print("\n教师列表:")
        for teacher in self.teachers:
            teacher.show()
        print("\n学生列表:")
        for student in self.students:
            student.show()
    # 创建学校对象
school = School(name="XYZ School", address="123 Main Street")
     # 创建教师对象
teacher1 = Teacher(name="Mr. Smith", age=40, gender="Male", salary=50000, course="Math")
teacher2 = Teacher(name="Ms. Johnson", age=35, gender="Female", salary=45000, course="English")
    # 创建学生对象
student1 = Student(name="Alice", age=18, gender="Female", student_id="S001", tuition=8000, course="Math")
student2 = Student(name="Bob", age=17, gender="Male", student_id="S002", tuition=7500, course="English")
    # 注册学生和雇佣教师
school.enroll(student1)
school.enroll(student2)
school.hire(teacher1)
school.hire(teacher2)
    # 输出学校信息
school.information()
    # 教师授课和学生缴费
teacher1.teach()
teacher2.teach()
student1.pay_tuition()
student2.pay_tuition()