import turtle
import time

def draw_traffic_light(x, y, radius, color):
    turtle.penup()
    turtle.goto(x, y - radius)
    turtle.pendown()
    turtle.color("black", color)
    turtle.begin_fill()
    turtle.circle(radius)
    turtle.end_fill()

def drawLine(draw):
    turtle.penup()
    turtle.fd(5)
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
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

def drawDate(date, start_position=(330, 100), digit_index=0):
    turtle.penup()
    turtle.goto(start_position)  # Move to starting position before loop
    turtle.pencolor("red")

    num = str(date)
    current_digit = int(num[digit_index])
    drawDigits(current_digit)
    turtle.penup()  # Lift pen after drawing each digit
    turtle.forward(40)  # Move forward for next digit

    if digit_index + 1 < len(num):
        # Schedule the next digit drawing after 0.5 seconds
        turtle.ontimer(drawDate, 500, False, (date, start_position, digit_index + 1))
    else:
        # Clear the entire display after drawing the last digit
        turtle.ontimer(clearDisplay, 500, False)

def clearDisplay():
    turtle.clear()
    turtle.penup()  # Lift pen before returning to starting position
    turtle.goto(start_position)  # Return to starting position for next number

# 画数码管
def countdown_timer(time, start_position=(330, 100)):
    global start_position
    turtle.speed(2)
    turtle.pensize(5)
    drawDate(time, start_position)
    turtle.done()

# 设置Turtle
t = turtle.Turtle()

# 设置窗口大小
width = 500
height = 200
turtle.setup(width, height)
turtle.setworldcoordinates(0, 0, width, height)

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

# 启动计时器
turtle.ontimer(countdown_timer, 500, False, 60)

# 关闭窗口时保持窗口打开
turtle.mainloop()
