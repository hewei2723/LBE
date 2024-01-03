class Animal:
    def __init__(self, name, age):
        # 姓名属性
        self.name = name
        # 年龄属性
        self.age = age
    # 吃饭行为
    def eat(self):
        print(f"{self.name} 正在吃东西")
    # 睡觉行为
    def sleep(self):
        print(f"{self.name} 正在睡觉")
class Dog(Animal):
    # Dog类继承Animal类的属性和方法
    pass
class Cat(Animal):
    # Cat类继承Animal类的属性和方法
    # 在Cat类中创建新的方法
    def play(self):
        print(f"{self.name} 正在玩耍")
    # 创建Dog类的实例对象
my_dog = Dog("小汪", 4)
my_dog.eat()  # 调用基类中的方法
    # 创建Cat类的实例对象
my_cat = Cat("小喵", 2)
my_cat.play()  # 调用Cat类中的方法
