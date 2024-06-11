class Animal:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def eat(self):
        print(f"{self.name} 正在吃东西")
    def sleep(self):
        print(f"{self.name} 正在睡觉")
class Dog(Animal):
    pass
class Cat(Animal):
    def play(self):
        print(f"{self.name} 正在玩耍")
my_dog = Dog("小汪", 4)
my_dog.eat()
my_cat = Cat("小喵", 2)
my_cat.play()
