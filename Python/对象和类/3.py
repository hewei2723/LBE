import math
# 创建Point类
class Point:
    # 初始化函数
    def __init__(self, x, y):
        self.x = x
        self.y = y
# 创建Line类
class Line:
    # 初始化函数
    def __init__(self, point1, point2):
        self.point1 = point1
        self.point2 = point2

    # 计算线段长度
    def _calculate_length(self):
        # 计算线段长度
        return math.sqrt((self.point2.x - self.point1.x)**2 + (self.point2.y - self.point1.y)**2)

    # 输出线段信息
    def __str__(self):
        # 输出属性的值
        return f"线段端点1: ({self.point1.x}, {self.point1.y}), 线段端点2: ({self.point2.x}, {self.point2.y}), 线段长度: {self._calculate_length():.2f}"
    # 创建两个Point对象
point1 = Point(1, 2)
point2 = Point(4, 6)

    # 创建Line对象
line = Line(point1, point2)

    # 输出线段信息
print(line)