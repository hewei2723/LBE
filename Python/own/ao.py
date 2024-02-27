import datetime
import turtle
name = []
def drawLine(draw):  # 绘制单段数码管
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
    turtle.right(90)
def drawLine1(draw):  # 绘制单段数码管1
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(20)
def drawtdown1(draw):  # 斜线
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(44.7)
def drawDigit(digit):  # 根据数字绘制七段数码管
    # 横1笔
    drawLine1(True) if digit in [2, 4, 5, 6, 8, 9, 'A', 'E', 'F', 'H',  'K', 'P', 'R', 'S'] else drawLine1(False)
   
    # 横2笔
    drawLine1(True) if digit in [2, 3, 4, 5, 6, 8, 9,'F', 'A','B','G','H','P,'R',S'] else drawLine1(False)
   
    # 第3笔
    turtle.right(90)
    drawLine(True) if digit in [0, 1, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'D', 'G', 'H', 'J', 'M', 'N' , 'O', 'Q', 'S', 'U', 'W'] else drawLine(False)
   
    # 第4笔
    drawLine(True) if digit in ['L',0, 2, 3, 5, 6, 8, 9, 'B', 'C', 'D', 'E', 'G', 'I', 'U','J', 'O', 'Q', 'S', 'Z'] else drawLine(False)
    
    # 第5笔
    drawLine(True) if digit in ['L',0, 2, 6, 8, 'A', 'C' , 'E' , 'F' , 'G', 'H' , 'J' , 'K' , 'L' , 'M' , 'N' ,'O' , 'P' , 'Q' ,'R' , 'U' , 'V' , 'W'] else drawLine(False)
   
    # 第6笔（因为会右转，这里调节第五笔为向上直线）
    turtle.left(90)
    drawLine(True) if digit in ['L',0, 4, 5, 6, 8, 9, 'A','C','E','F','G','H','K','M','N','O','P','Q','R','S','U','V','W'] else drawLine(False)
  
    # 第7笔
    drawLine(True) if digit in [0, 2, 3, 5, 6, 7, 8, 9, 'A','B','C','D','E','F','G','O','P','Q','R','I','S','T','Z'] else drawLine(False)
   
    # 第8笔
    drawLine(True) if digit in [0, 1, 2, 3, 4, 7, 8, 9, 'A','B','D','H','J','M','N','O','P','Q','R','U','W'] else drawLine(False)
  
    # 第9笔
    turtle.left(90)
    turtle.penup()
    turtle.fd(40)
    turtle.right(90 + 63.4)
    drawtdown1(True) if digit in ['K','N','Q','K','N','Q','R','W','X'] else drawtdown1(False)
  
    # 第10笔********************
    drawtdown1(True) if digit in ['M','N','X','Y'] else drawtdown1(False)
  
    # 第11笔********************
    turtle.right(90 + 26.6)
    turtle.penup()
    turtle.fd(20)
    turtle.right(90)
    drawLine(True) if digit in ['B','D','I','T'] else drawLine(False)
   
    # 第12笔***********
    turtle.left(90)
    drawLine(True) if digit in ['B','D','I','T','Y'] else drawLine(False)
    turtle.penup()
    turtle.fd(20)
    turtle.right(90 + 26.6)
    drawtdown1(True) if digit in ['V','X','Z','W', 0] else drawtdown1(False)
    drawtdown1(True) if digit in ['M','V','X','Y','Z','K', 0, 1] else drawtdown1(False)
    turtle.right(90 + 63.4)
    turtle.penup()
    turtle.fd(40)
    turtle.left(90)
    turtle.fd(20)
def drawname():
    beijing = ['B', 'E', 'I', 'J', 'I', 'N', 'G']
    shanghai = ['S', 'H', 'A', 'N', 'G', 'H', 'A', 'I']
    taipei = ['T', 'A', 'I', 'P', 'E', 'I']
    yancheng = ['Y', 'A', 'N', 'C', 'H', 'E', 'N', 'G']
    weather1 = ['R', 'A', 'I', 'N']
    weather2 = ['C', 'L', 'E', 'A','R']
#    city='台北'   
    city = input("请输入城市名：")
    city = city.strip()  # 去除输入城市名的首尾空格，以防止匹配失败
    
    turtle.pensize(5)
    turtle.speed(0)
    
    if city == '北京':
        turtle.color("red")  # 设置画笔颜色为红色
        for i in beijing:
            drawDigit(i)
        turtle.color("black")  # 恢复画笔颜色为黑色
        turtle.color("blue")  # 设置画笔颜色为蓝色
        turtle.goto(150, 50)
        for i in weather1:
            drawDigit(i)    
        turtle.goto(-200, -50)
        turtle.color("black")  # 恢复画笔颜色为黑色
        drawDigit(2)  # 绘制数字2
        drawDigit(1)  # 绘制数字0
        turtle.goto(-50, -50)
        turtle.color("gray") 
        drawDigit('C')
    elif city == '上海':
        turtle.color("red")  # 设置画笔颜色为红色
        for i in shanghai:
            drawDigit(i)
        turtle.color("black")  # 恢复画笔颜色为黑色
        turtle.color("blue")  # 设置画笔颜色为蓝色
        turtle.goto(160, 50)
        for i in weather1:
            drawDigit(i)    
        turtle.goto(-200, -50)
        turtle.color("black")  # 恢复画笔颜色为黑色
        drawDigit(2)  # 绘制数字2
        drawDigit(1)  # 绘制数字0
        turtle.goto(-50, -50)
        turtle.color("gray") 
        drawDigit('C')
    elif city == '台北':
        turtle.color("red")  # 设置画笔颜色为红色
        for i in taipei:
            drawDigit(i)
        turtle.color("black")  # 恢复画笔颜色为黑色
        turtle.color("blue")  # 设置画笔颜色为蓝色
        turtle.goto(100, 50)
        for i in weather2:
            drawDigit(i)    
        turtle.goto(-200, -50)
        turtle.color("black")  # 恢复画笔颜色为黑色
        drawDigit(2)  # 绘制数字2
        drawDigit(1)  # 绘制数字0
        turtle.goto(-50, -50)
        turtle.color("gray") 
        drawDigit('C')
    elif city == '盐城':
        turtle.color("red")  # 设置画笔颜色为红色
        for i in yancheng:
            drawDigit(i)
        turtle.color("black")  # 恢复画笔颜色为黑色
        turtle.color("blue")  # 设置画笔颜色为蓝色
        turtle.goto(160, 50)
        for i in weather1:
            drawDigit(i)    
        turtle.goto(-200, -50)
        turtle.color("black")  # 恢复画笔颜色为黑色
        drawDigit(2)  # 绘制数字2
        drawDigit(4)  # 绘制数字0
        turtle.goto(-50, -50)
        turtle.color("gray") 
        drawDigit('C')
# 定义主函数
def main():
    # 设置画布大小，位置，画笔大小，画笔颜色，画笔速度
    turtle.setup(800, 350, 0, 0)
    turtle.penup()
    # 画出一条线，从（-330，50）到（-330，-50）
    turtle.goto(-330, 50)
    turtle.pensize(5)
    turtle.pencolor("black")
    turtle.speed(0)    
    # 调用绘制名字函数
    drawname()
    # 隐藏画笔
    turtle.hideturtle()
    # 点击鼠标退出程序
    turtle.exitonclick()
main()

