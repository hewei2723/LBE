a_list=[]
while True:
    s=input()
    if s=="*":
        break
    a_list.append(s+"\n")

fp=open(".//1.txt","a")
fp.writelines(a_list)
fp.close()
fp=open(".//1.txt","r")
str=fp.read()
fp.close()
print("输出文本文件内容：")
print(str)