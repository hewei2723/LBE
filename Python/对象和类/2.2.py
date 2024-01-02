class Animal:
    def __init__(self, name, age):
        # 姓名属性
        self.name = name
        # 年龄属性
        self.age = age

class Dog(Animal):
    def __init__(self, name, age, vaccine):
        # 调用基类的初始化方法
        super().__init__(name, age)
        # 是否打过疫苗属性
        self.vaccine = vaccine

    def show_info(self):
        if self.vaccine:
            print(f"{self.name} 打过疫苗了")
        else:
            print(f"{self.name} 还没打过疫苗")

if __name__ == "__main__":
    # 创建 Dog 类的实例对象
    my_dog = Dog("小汪", 4, True)

    # 调用 Dog 类中的 show_info 方法
    my_dog.show_info()
