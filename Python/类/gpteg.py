class myclass:
    def __init__(self,name):
        self.name = name
    def say_hi(self):
        print("Hi, my name is " + self.name)
obj = myclass("Swaroop")
obj.say_hi()
print(obj.name)