class Animal:
    def __init__(self, species):
        self.species = species
    def make_sound(self):
        print("Some generic sound")
class Cat(Animal):
    def __init__(self, name):
        # 调用父类的构造函数
        super().__init__(species="Cat")
        self.name = name
    # 覆盖父类的方法
    def make_sound(self):
        print("Meow!")
# 创建 Cat 类的实例
my_cat = Cat(name="Whiskers")
# 调用继承的属性和方法
print(my_cat.species)  # 输出: Cat
my_cat.make_sound()    # 输出: Meow!
