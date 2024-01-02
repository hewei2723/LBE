class Phone:
    # 定义一个函数，用于初始化一个对象
    def __init__(self, brand, color, os):
        self.brand = brand
        self.color = color
        self.os = os

# 定义一个函数，用于给指定的人打电话
    def make_call(self, recipient):
        print(f"正在给 {recipient} 打电话...")

# 定义一个函数，用于观看电视
    def watch_tv(self):
        print("正在观看电视...")

# 定义一个函数，用于听音乐
    def listen_music(self):
        print("正在听音乐...")

if __name__ == "__main__":
    # 创建手机对象
    my_phone = Phone(brand="ExampleBrand", color="Black", os="Android")

    # 调用手机方法
    my_phone.make_call("张三")
    my_phone.watch_tv()
    my_phone.listen_music()
