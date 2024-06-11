class Computer:
    one = 0 
    two = 0 
    op = ""
    result = 0
    def __init__(self,sone,stwo):
        self.one=sone
        self.two=stwo
    def addone(self):
        result = one + two
        return result
    def minus(self):
        result = one - two
        return result
    def multiply(self):
        result = one * two
        return result
    def division(self):
        result = one / two
        return result
print("我可以帮你算数字")
flag = True
while flag:
    one = int(input("第1个数:"))
    two = int(input("第2个数:"))
    operation=input("+-*/?:")

    cp=Computer(one,two)
    if operation=="+":
        print(cp.addone())
    elif operation=="-":
        print(cp.minus())
    elif operation=="*":
        print(cp.multiply())
    elif operation=="/":
        print(cp.division())
    else:
        print("你输错了")