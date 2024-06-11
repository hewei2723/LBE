def f():
    global x
    x=30
    y=40
    print("NO2:",x,y)
x=10
y=20
print("NO1:",x,y)
f()
print("NO3:",x,y)
