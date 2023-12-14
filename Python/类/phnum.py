class Contact:
    def __init__(self, name, phone_number):
        self.name = name
        self.phone_number = phone_number

class AddressBook:
    def __init__(self):
        # 初始化通讯录
        self.contacts = []

    def add_contact(self, name, phone_number):
        # 创建一个新的联系人对象
        new_contact = Contact(name, phone_number)
        # 将联系人对象添加到通讯录
        self.contacts.append(new_contact)

    def find_contact(self, name):
        for contact in self.contacts:
            if contact.name == name:
                return contact
        return None  # 如果联系人未找到，返回 None

    def display_contacts(self):
        for contact in self.contacts:
            print(contact.name, contact.phone_number)

# 测试通讯录功能
address_book = AddressBook()

# 添加联系人
while True:
    name = input("请输入姓名：")
    num = input("请输入电话号码：")
    if name == 'q':
        break
    address_book.add_contact(name, num)
# 查找联系人
name = input("请输入姓名：")
contact = address_book.find_contact(name)
if contact:
    print("找到了联系人：", contact.name, contact.phone_number)
else:
    print("找不到联系人：", name)              
# 显示联系人
address_book.display_contacts()