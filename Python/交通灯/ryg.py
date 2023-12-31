import turtle
import time

def draw_traffic_light(x, y, radius, color, label):
    t.penup()
    t.goto(x, y - radius)  # 移动到圆心位置
    t.pendown()
    t.speed(100)
    
    # 画圆
    t.color("black", color)
    t.begin_fill()
    t.circle(radius)
    t.end_fill()
    
    # 添加文字说明
    t.penup()
    t.goto(x, y - radius - 20)  # 调整文字位置
    t.pendown()
    t.write(label, align="center", font=("Arial", 10, "normal"))

def rbb():
    draw_traffic_light(50, 100, traffic_light_radius, "red", "红灯禁止通行\nhewei2723制作")
    draw_traffic_light(150, 100, traffic_light_radius, "gray", "")
    draw_traffic_light(250, 100, traffic_light_radius, "gray", "")
    countdown_timer(5)
    byb()
    bbg()

def byb():
    draw_traffic_light(50, 100, traffic_light_radius, "gray", "")
    draw_traffic_light(150, 100, traffic_light_radius, "yellow", "黄灯请等待\nhewei2723制作")
    draw_traffic_light(250, 100, traffic_light_radius, "gray", "")
    countdown_timer(3)

def bbg():
    draw_traffic_light(50, 100, traffic_light_radius, "gray", "")
    draw_traffic_light(150, 100, traffic_light_radius, "gray", "")
    draw_traffic_light(250, 100, traffic_light_radius, "green", "绿灯可以通行\nhewei2723制作")
    countdown_timer(5)
    byb()
    rbb()

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
    turtle.goto(start_position)
    turtle.pencolor("red")
    for i in reversed(range(date + 1)):
        num = str(i)
        for n in num:
            drawDigits(eval(n))
            turtle.penup()
            turtle.forward(40)
        turtle.clear()
        turtle.penup()
        turtle.goto(start_position)

def countdown_timer(time, start_position=(330, 100)):
    turtle.pensize(5)
    turtle.speed(50)
    drawDate(time, start_position)

t = turtle.Turtle()
t.hideturtle()
width = 500
height = 200
turtle.setup(width, height)
turtle.setworldcoordinates(0, 0, width, height)
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

traffic_light_radius = 30
rbb()
turtle.mainloop()