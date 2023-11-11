import random
t = [random.randint(0, 100) for i in range(10)]
a= t[0:5]
b= t[5:10]
a.sort()
b.sort(reverse=True)
c=a+b
print(c)