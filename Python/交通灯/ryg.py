import turtle
import time
def draw_traffic_light(x, y, radius, color):
    t.penup()
    t.goto(x, y - radius)  # 移动到圆心位置
    t.pendown()
    t.speed(50)
    t.color("black", color)
    t.begin_fill()
    t.circle(radius)  # 画圆
    t.end_fill()

def rbb():
    draw_traffic_light(50, 100, traffic_light_radius, "red")
    draw_traffic_light(150, 100, traffic_light_radius, "gray")
    draw_traffic_light(250, 100, traffic_light_radius, "gray")
    countdown_timer(3)#设置红灯时间刻
    byb()

def byb():
    draw_traffic_light(50, 100, traffic_light_radius, "gray")
    draw_traffic_light(150, 100, traffic_light_radius, "yellow")
    draw_traffic_light(250, 100, traffic_light_radius, "gray")
    countdown_timer(1)#设置黄灯时间刻
    bbg()

def bbg():
    draw_traffic_light(50, 100, traffic_light_radius, "gray")
    draw_traffic_light(150, 100, traffic_light_radius, "gray")
    draw_traffic_light(250, 100, traffic_light_radius, "green")
    countdown_timer(3)#设置绿灯时间刻
    rbb()
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

def drawDigits(digit):
    drawLine(True) if digit in [2, 3, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 6, 8] else drawLine(False)
    turtle.left(90)
    drawLine(True) if digit in [0, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(15)

def drawDate(date, start_position=(330, 100)):
    turtle.penup()
    turtle.goto(start_position)  # Move to starting position before loop
    turtle.pencolor("red")
    for i in reversed(range(date + 1)):
        num = str(i)
        for n in num:
            drawDigits(eval(n))
            turtle.penup()  # Lift pen after drawing each digit
            turtle.forward(40)  # Move forward for next digit
        turtle.clear()
        turtle.penup()  # Lift pen before returning to starting position
        turtle.goto(start_position)  # Return to starting position for next number
        #screen.update()

#画数码管
def countdown_timer(time, start_position=(330, 100)):
    turtle.pensize(5)
    turtle.speed(50)#调整画管子的速度刻
    drawDate(time, start_position)
#    turtle.done()
# 设置Turtle
t = turtle.Turtle()
t.hideturtle()
# 设置窗口大小
width = 500
height = 200
turtle.setup(width, height)
turtle.setworldcoordinates(0, 0, width, height)

# 获取屏幕对象并关闭动画
#screen = turtle.Screen()
#screen.tracer(0, 0)

# 画四条竖线，将方框分成5部分
num_lines = 4
line_spacing = width / (num_lines + 1)
t.speed(100)
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
#screen.update()
# 关闭窗口时保持窗口打开
turtle.mainloop()