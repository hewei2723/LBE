class goods:
    id=''#商品id
    num=''#商品余量
    name=''#商品名
    def __init__(self,gid,gnum,gname) -> None:
        self.id=gid
        self.num=gnum
        self.name=gname
        pass
class userclass Goods:
    id = ''  # 商品id
    num = ''  # 商品余量
    name = ''  # 商品名

    def __init__(self, gid, gnum, gname) -> None:
        self.id = gid
        self.num = gnum
        self.name = gname

class User:
    upri = 0  # 价钱
    uid = 0
    num = 0  # 数量

    def buy(self, i, gnum):
        self.upri = glist[i - 1][1] * gnum
        return self.upri

glist = [["1 iphone15", 8999], ["2 小米6 ", 3699], ["3 华为NOVA 11 SE", 1999]]
blist = []
for i in glist:
    print(i)

finalpri = 0
str1 = ""
while True:
    print("输入0退出")
    sgid = input("请输入商品编号")
    sgnum = input("请输入商品数量")
    goodid = int(sgid)
    goodnum = int(sgnum)

    if goodid <= 0 or goodnum <= 0 or goodid > len(glist):
        print("输入无效，请重新输入")
        continue
    elif goodid == 0 or goodnum == 0:
        if len(blist) < 1:
            print("你什么都不买？")
        for j in blist:
            print(j)
        print("总价为：" + str(finalpri))
        input()
    else:
        user1 = User()
        user1.buy(goodid, goodnum)
        str1 = f"{glist[goodid - 1][0]} 数量：{sgnum}"
        blist.append(str1)

    finalpri = finalpri + int(user1.upri)
    print()
    for i in blist:
        print(i)

    upri=0 #价钱
    uid=0 
    num=0#数量
    def buy(self,i,gnum):
        self.upri=glist[i-1][1]*gnum
        return self.upri
glist=[["1 iphone15",8999],["2 小米6 ",3699],["3 华为NOVA 11 SE",1999]]
blist=[]
for i in glist:
    print(i)
finalpri=0
str1=""
while True:
    print("输入0退出")
    sgid=input("请输入商品编号")
    sgnum=input("请输入商品数量")
    goodid=int(sgid)
    goodnum=int(sgnum)
    if goodid>len(glist):
        print("你要的商品不存在")
        continue
    elif goodid==0 or goodnum==0:
        if len(blist)<1:
            print("你什么都不买？")
        for j in blist:
            print(j)
        print("总价为："+str(finalpri))
        input()
    else:
        user1=user()
        user1.buy(goodid,goodnum)
        str1=str(glist[goodid-1]+"数量："+sgnum)
        blist.append(str1)
    finalpri=finalpri+int(user1.upri)
    print()
    for i in blist:
        print(i)

