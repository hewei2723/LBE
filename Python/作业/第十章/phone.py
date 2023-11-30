class phone:
    def __init__(self,brand,color,os):
        self.brand = brand
        self.color = color
        phone.os = os
    def call(self,name):
        print('我打电话给{}'.format(name))
    @classmethod
    def kantv(cls):
        print("i'm watching tv")
    @classmethod
    def music(self,music="hhh"):
        print('我在听歌，听的是{}'.format(music))
p=phone('HUAWEI','black','HarmonyOS')
p.call('雷军')
phone.music("Are you ok?")
phone.kantv()