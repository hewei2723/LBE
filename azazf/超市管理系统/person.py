class Employ:
    #员工信息
    def __init__(self,Ename,Epnum,Edress,Edegree) -> None:
        self.Ename = Ename #员工名字
        self.Epnum = Epnum #员工电话
        self.Edress = Edress #员工地址
        self.Edegree = Edegree #员工职位
    def add_E():
        Ename = input("请输入员工名字：")
        Epnum = input("请输入员工电话：")
        Edress = input("请输入员工地址：")
        Edegree = input("请输入员工职位：")
        E = Employ(Ename,Epnum,Edress,Edegree)
        return E
    def del_E():
        Ename = input("请输入员工名字：")
        E = Employ(Ename)
        return E
    def update_E():
        Ename = input("请输入员工名字：")
        Epnum = input("请输入员工电话：")
        Edress = input("请输入员工地址：")
        Edegree = input("请输入员工职位：")
    def list_E():
        Elist = []
        for E in Employ.Elist:
            print(E.Ename)
            print(E.Epnum)
            print(E.Edress)
            print(E.Edegree)
class vip:
    def __init__(self,Vpnum,Vname,Vpoint) -> None:
        self.Vpnum = Vpnum #会员编号
        self.Vname = Vname #会员名字
        self.Vpoint = Vpoint #会员积分
    def add_V():
        Vpnum = input("请输入会员编号：")
        Vname = input("请输入会员名字：")
        Vpoint = input("请输入会员积分：")
        V = vip(Vpnum,Vname,Vpoint)
        return V
    def del_V():
        Vpnum = input("请输入会员编号：")
        V = vip(Vpnum)
        return V
    def update_V():
        Vpnum = input("请输入会员编号：")
        Vname = input("请输入会员名字：")
        Vpoint = input("请输入会员积分：")
    def list_V():
        Vlist = []
        for V in vip.Vlist:
            print(V.Vpnum)
            print(V.Vname)
   
    