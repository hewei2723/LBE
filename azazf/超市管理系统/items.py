import os
import csv
s_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'items.csv')
class items:
    def __init__(self,Sname,Sid,Snum,Spri) -> None:
        self.name = Sname
        self.id = Sid
        self.num = Snum
        self.pri = Spri

    def add_S(): #增加商品
        Sname = input("请输入商品名称：")
        Sid = input("请输入商品编号：")
        Snum = int(input("请输入商品数量："))
        Spri = int(input("请输入商品价格："))
        with open(s_csv_path, 'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([Sname,Sid,Snum,Spri])
    def del_S(): #删除商品
        pass    
    def rep_S(): #库存商品
        pass
    def list_S(): #列出库存
        pass
    def update_S(): #修改商品
        pass