import turtle
import os
import requests
import json
# 获取当前脚本所在的文件夹路径
# 获取当前脚本所在的文件夹路径
current_directory = os.path.dirname(os.path.abspath(__file__))
# 构建字体文件的完整路径
font_path = os.path.join(current_directory, "DS-DIGI-1.ttf")
def get_weather():
    url = 'http://t.weather.sojson.com/api/weather/city/'

    # 输入城市中文
    city_name = input("请输入你要查询的城市：")

    # 读取json文件
    city_file_path = os.path.join(current_directory, "city.json")
    with open(city_file_path, 'r', encoding='utf-8') as f:
        cities = json.load(f)

    # 通过城市的中文获取城市代码
    city_code = cities.get(city_name)

    # 网络请求，传入请求api+城市代码
    response = requests.get(url + str(city_code))

    # 将数据以json形式返回
    weather_data = response.json()

    # 获取城市名称
    city_info = weather_data["cityInfo"]
    city = city_info['city']

    # 获取温度信息
    forecast_info = weather_data["data"]["forecast"][0]
    temperature = forecast_info["high"]

    return {"city": city, "weather": forecast_info["type"], "temperature": temperature}
def drawNumber(number):
    for n in str(number):
        drawDigits(int(n))
def drawDate(temp, start=(410, 100)):
    turtle.penup()
    turtle.goto(start)
    turtle.pencolor("red")
    # 提取温度数字部分
    temperature = int(''.join(filter(str.isdigit, temp)))
    drawNumber(temperature)
def drawGap():
    turtle.penup()
    turtle.fd(5)
def drawLine(draw):
    drawGap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(50)
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
def drawDate(temp, start=(410, 100)):
    turtle.penup()
    turtle.goto(start)
    turtle.pencolor("red")
    # 提取温度数字部分
    temperature = int(''.join(filter(str.isdigit, temp)))
    drawNumber(temperature)
def drawtext(text, start_x, start_y, font_size):
    pen = turtle.Turtle()
    turtle.bgcolor("white")
    pen.color("black")
    pen.pensize(2)
    pen.penup()
    pen.goto(start_x, start_y)
    pen.pendown()
    # 设置字体
    font_style = (font_path, font_size, "normal")
    pen.write(text, font=font_style, align="left")
    pen.hideturtle()
t = turtle.Turtle()
t.hideturtle()
width = 600
height = 200
turtle.setup(width, height)
turtle.bgcolor("#1e90ff")
turtle.setworldcoordinates(0, 0, width, height)
num_lines = 2
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
def main():
    weather_info = get_weather()
    # 打印天气信息
    print("城市：", weather_info["city"])
    print("天气：", weather_info["weather"])
    print("温度：", weather_info["temperature"])
    # 绘制天气信息
    drawtext(weather_info["city"], 50, 80, 30)
    drawtext(weather_info["weather"], 250, 80, 30)
    drawtext("°C", 560, 50, 10)
    drawDate(weather_info["temperature"])
    turtle.done()
if __name__ == "__main__":
    main()

