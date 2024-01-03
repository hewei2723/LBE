import math
# 定义一个Circle类，构造函数接收一个参数radius
class Circle:
    def __init__(self, radius):
        self.radius = radius
    # 定义一个area方法，返回圆的面积
    def area(self):
        return round(math.pi * self.radius**2, 1)
    # 定义一个perimeter方法，返回圆的周长
    def perimeter(self):
        return round(2 * math.pi * self.radius, 1)

radius_input = float(input("请输入圆的半径: "))    
    # 定义一个函数，参数为radius_input，返回一个Circle对象
circle = Circle(radius_input)    
    # 计算圆的面积
area_result = circle.area()
perimeter_result = circle.perimeter()
print(f"半径为{radius_input:.1f}的圆的面积是:{area_result}\n半径为{radius_input:.1f}的圆的周长是:{perimeter_result}")
