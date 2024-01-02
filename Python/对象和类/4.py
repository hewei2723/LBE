class Person:
    def __init__(self, name, age):
        self.name = name
        self._age = age  # _age为私有属性

    # 访问私有属性的方法
    def get_age(self):
        return self._age

    # 设置私有属性的方法
    def set_age(self, age):
        self._age = age

    # 输出所有属性的值的方法
    def display_info(self):
        print(f"姓名: {self.name}, 年龄: {self._age}")

class Worker(Person):
    def __init__(self, name, age, salary):
        super().__init__(name, age)
        self.salary = salary

    # 输出所有属性的值的方法，包括继承自父类的属性
    def display_info(self):
        super().display_info()
        print(f"薪水: {self.salary}")

if __name__ == "__main__":
    # 创建Person对象
    person = Person(name="John", age=25)

    # 输出Person对象的属性值
    person.display_info()

    # 修改私有属性_age的值
    person.set_age(30)

    # 创建Worker对象
    worker = Worker(name="Alice", age=35, salary=50000)

    # 输出Worker对象的属性值
    worker.display_info()
