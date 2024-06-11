class SchoolMember:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender
    def show(self):
        pass
class Teacher(SchoolMember):
    def __init__(self, name, age, gender, salary, course):
        super().__init__(name, age, gender)
        self.salary = salary
        self.course = course
    def show(self):
        print(f"教师信息 - 姓名: {self.name}, 年龄: {self.age}, 性别: {self.gender}, 酬金: {self.salary}, 课程: {self.course}")
    def teach(self):
        print(f"{self.name} 正在教授 {self.course} 课程")
class 面向对象编程.own.Student(SchoolMember):
    def __init__(self, name, age, gender, student_id, tuition, course):
        super().__init__(name, age, gender)
        self.student_id = student_id
        self.tuition = tuition
        self.course = course
    def show(self):
        print(f"学生信息 - 姓名: {self.name}, 年龄: {self.age}, 性别: {self.gender}, 学生ID: {self.student_id}, 学费: {self.tuition}, 课程: {self.course}")
    def pay_tuition(self):
        print(f"{self.name} 缴纳了学费 {self.tuition}")
class School:
    def __init__(self, name, address):
        self.name = name
        self.address = address
        self.teachers = []
        self.students = []
    def enroll(self, student):
        self.students.append(student)
        print(f"{student.name} 已成功注册到 {self.name}")
    def hire(self, teacher):
        self.teachers.append(teacher)
        print(f"{teacher.name} 已成功加入 {self.name} 的教师队伍")
    def information(self):
        print(f"\n学校信息 - 名称: {self.name}, 地址: {self.address}")
        print("\n教师列表:")
        for teacher in self.teachers:
            teacher.show()
        print("\n学生列表:")
        for student in self.students:
            student.show()
school = School(name="XYZ School", address="123 Main1231 Street")
teacher1 = Teacher(name="Mr. Smith", age=40, gender="Male", salary=50000, course="Math")
teacher2 = Teacher(name="Ms. Johnson", age=35, gender="Female", salary=45000, course="English")
student1 = 面向对象编程.own.Student(name="Alice", age=18, gender="Female", student_id="S001", tuition=8000, course="Math")
student2 = 面向对象编程.own.Student(name="Bob", age=17, gender="Male", student_id="S002", tuition=7500, course="English")
school.enroll(student1)
school.enroll(student2)
school.hire(teacher1)
school.hire(teacher2)
school.information()
teacher1.teach()
teacher2.teach()
student1.pay_tuition()
student2.pay_tuition()