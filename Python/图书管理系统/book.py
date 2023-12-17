import csv
import os
books_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'books.csv')
def list_books():
    # 打开books_csv_path文件，以只读的方式
    with open(books_csv_path, 'r') as f:
        # 创建csv.reader对象，用于读取csv文件
        reader = csv.reader(f)
        # 遍历每一行，打印每一行
        for row in reader:
            print(row)

def add_book():
    # 输入书名
    book_name = input("请输入书名：")
    # 输入作者
    book_author = input("请输入作者：")
    # 输入数量
    book_quantity = input("请输入数量：")

    # 以追加的方式打开books_csv_path文件，以写入的方式
    with open(books_csv_path, 'a', newline='') as f:
        # 创建csv.writer对象，用于写入csv文件
        writer = csv.writer(f)
        # 将书名、作者、数量写入csv文件
        writer.writerow([book_name, book_author, book_quantity])

def delete_book():
    # 输入要删除的书名
    book_name = input("请输入要删除的书名：")

    # 创建一个空列表，用于存储处理后的数据
    lines = []
    # 以只读的方式打开books_csv_path文件，以读取的方式
    with open(books_csv_path, 'r') as f:
        # 创建csv.reader对象，用于读取csv文件
        reader = csv.reader(f)
        # 遍历每一行，如果书名不等于要删除的书名，则将该行添加到lines列表中
        lines = [row for row in reader if row[0] != book_name]

    # 以写入的方式打开books_csv_path文件，以写入的方式
    with open(books_csv_path, 'w', newline='') as f:
        # 创建csv.writer对象，用于写入csv文件
        writer = csv.writer(f)
        # 将处理后的数据写入csv文件
        writer.writerows(lines)

def update_book():
    # 输入要更新的书名
    book_name = input("请输入要更新的书名：")

    # 创建一个空列表，用于存储处理后的数据
    lines = []
    # 以只读的方式打开books_csv_path文件，以读取的方式
    with open(books_csv_path, 'r') as f:
        # 创建csv.reader对象，用于读取csv文件
        reader = csv.reader(f)
        # 遍历每一行，如果书名不等于要更新的书名，则将该行添加到lines列表中
        lines = [row for row in reader if row[0] != book_name]

    # 输入新的作者
    book_author = input("请输入新的作者：")
    # 输入新的数量
    book_quantity = input("请输入新的数量：")
    # 将新的书名、作者、数量添加到lines列表中
    lines.append([book_name, book_author, book_quantity])

    # 以写入的方式打开books_csv_path文件，以写入的方式
    with open(books_csv_path, 'w', newline='') as f:
        # 创建csv.writer对象，用于写入csv文件
        writer = csv.writer(f)
        # 将处理后的数据写入csv文件
        writer.writerows(lines)
def borrow_book():
    # 输入要借阅的书名
    book_name = input("请输入要借阅的书名：")
    # 创建一个空列表，用于存储处理后的数据
    lines = []
    # 以只读的方式打开books_csv_path文件，以读取的方式
    with open(books_csv_path, 'r') as f:
        # 创建csv.reader对象，用于读取csv文件
        reader = csv.reader(f)
        # 遍历每一行，如果书名等于要借阅的书名，则将该行添加到lines列表中
        lines = [row for row in reader]
    # 遍历每一行，如果书名等于要借阅的书名，且数量大于0，则将该行数量减1，并打印借书成功
    for row in lines:
        if row[0] == book_name:
            if int(row[2]) > 0:
                row[2] = str(int(row[2]) - 1)
                print("借书成功！")
            else:
                print("这本书已经被借完了。")
            break
    # 以写入的方式打开books_csv_path文件，以写入的方式
    with open(books_csv_path, 'w', newline='') as f:
        # 创建csv.writer对象，用于写入csv文件
        writer = csv.writer(f)
        # 将处理后的数据写入csv文件
        writer.writerows(lines)
def return_book():
    # 输入要归还的书名
    book_name = input("请输入要归还的书名：")

    # 创建一个空列表，用于存储处理后的数据
    lines = []
    # 以只读的方式打开books_csv_path文件，以读取的方式
    with open(books_csv_path, 'r') as f:
        # 创建csv.reader对象，用于读取csv文件
        reader = csv.reader(f)
        # 遍历每一行，如果书名等于要归还的书名，则将该行添加到lines列表中
        lines = [row for row in reader]

    # 遍历每一行，如果书名等于要归还的书名，则将该行数量加1，并打印还书成功
    for row in lines:
        if row[0] == book_name:
            row[2] = str(int(row[2]) + 1)
            print("还书成功！")
            break

    # 以写入的方式打开books_csv_path文件，以写入的方式
    with open(books_csv_path, 'w', newline='') as f:
        # 创建csv.writer对象，用于写入csv文件
        writer = csv.writer(f)
        # 将处理后的数据写入csv文件
        writer.writerows(lines)
