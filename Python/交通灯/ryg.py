import turtle
import time
def draw_traffic_light(x, y, radius, color):
    t.penup()
    t.goto(x, y - radius)  # 移动到圆心位置
    t.pendown()
    t.color("black", color)
    t.begin_fill()
    t.circle(radius)  # 画圆
    t.end_fill()

def countdown_function(total_seconds):
    while total_seconds > 0:
        minutes, seconds = divmod(total_seconds, 60)
        ten, one = divmod(seconds, 10)
        # 绘制十位和个位数码管
        drawDigit(ten, 330, 100)
        drawDigit(one, 430, 100)
        screen.update()
        time.sleep(1)
        total_seconds -= 1
def rbb():
    draw_traffic_light(50, 100, traffic_light_radius, "red")
    draw_traffic_light(150, 100, traffic_light_radius, "gray")
    draw_traffic_light(250, 100, traffic_light_radius, "gray")
    countdown_function(10)
    #turtle.ontimer(byb, 3000)  # 3秒后调用byb函数

def byb():
    draw_traffic_light(50, 100, traffic_light_radius, "gray")
    draw_traffic_light(150, 100, traffic_light_radius, "yellow")
    draw_traffic_light(250, 100, traffic_light_radius, "gray")
    turtle.ontimer(bbg, 1000)  # 1秒后调用bbg函数

def bbg():
    draw_traffic_light(50, 100, traffic_light_radius, "gray")
    draw_traffic_light(150, 100, traffic_light_radius, "gray")
    draw_traffic_light(250, 100, traffic_light_radius, "green")
    turtle.ontimer(rbb, 3000)  # 3秒后调用rbb函数
#这里绘制七段管
def drawGap():
    turtle.penup()
    turtle.fd(5)

def drawLine(draw):
    drawGap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
    drawGap()
    turtle.right(90)

def drawDigit(digit, start_x, start_y):
    turtle.penup()
    turtle.goto(start_x, start_y)
    turtle.clear()  # 清除之前的内容
    
    drawLine(True) if digit in [2, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 6, 8] else drawLine(False)
    turtle.left(90)
    drawLine(True) if digit in [0, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(20)
# 设置Turtle
t = turtle.Turtle()

# 设置窗口大小
width = 500
height = 200
turtle.setup(width, height)
turtle.setworldcoordinates(0, 0, width, height)

# 获取屏幕对象并关闭动画
screen = turtle.Screen()
screen.tracer(0, 0)

# 画四条竖线，将方框分成5部分
num_lines = 4
line_spacing = width / (num_lines + 1)

for i in range(1, num_lines + 1):
    x = i * line_spacing
    t.penup()
    t.goto(x, 0)
    t.pendown()
    t.left(90)
    t.forward(height)
    t.right(90)

# 交通信号灯的半径
traffic_light_radius = 30

# 绘制红色交通灯
rbb()
screen.update()
# 关闭窗口时保持窗口打开
turtle.mainloop()