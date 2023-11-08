a,b,c=(input("输入a,b,c的值:\n").split(','))
a = int(a)
b = int(b)
c = int(c)
d = 0
x = []
for i in range(0,c):
    d+=a
    a=a+b
    x.append(a)
print(x,len(x),d,d/len(x)) #输出数组

