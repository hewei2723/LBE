def fun():
    i=0
    while i<200:
        i+=1
        if i%3==0 and i%10==6:
            print(i)
print(fun())