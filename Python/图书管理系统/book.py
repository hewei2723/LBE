import csv
import os
books_csv_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'books.csv')
def list_books():
    with open(books_csv_path, 'r') as f:
        reader = csv.reader(f)
        for row in reader:
            print(row)

def add_book():
    book_name = input("请输入书名：")
    book_author = input("请输入作者：")
    book_quantity = input("请输入数量：")

    with open(books_csv_path, 'a', newline='') as f:
        writer = csv.writer(f)
        writer.writerow([book_name, book_author, book_quantity])

def delete_book():
    book_name = input("请输入要删除的书名：")

    lines = []
    with open(books_csv_path, 'r') as f:
        reader = csv.reader(f)
        lines = [row for row in reader if row[0] != book_name]

    with open(books_csv_path, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(lines)

def update_book():
    book_name = input("请输入要更新的书名：")

    lines = []
    with open(books_csv_path, 'r') as f:
        reader = csv.reader(f)
        lines = [row for row in reader if row[0] != book_name]

    book_author = input("请输入新的作者：")
    book_quantity = input("请输入新的数量：")
    lines.append([book_name, book_author, book_quantity])

    with open(books_csv_path, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(lines)
def borrow_book():
    book_name = input("请输入要借阅的书名：")

    lines = []
    with open(books_csv_path, 'r') as f:
        reader = csv.reader(f)
        lines = [row for row in reader]

    for row in lines:
        if row[0] == book_name:
            if int(row[2]) > 0:
                row[2] = str(int(row[2]) - 1)
                print("借书成功！")
            else:
                print("这本书已经被借完了。")
            break

    with open(books_csv_path, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(lines)


def return_book():
    book_name = input("请输入要归还的书名：")

    lines = []
    with open(books_csv_path, 'r') as f:
        reader = csv.reader(f)
        lines = [row for row in reader]

    for row in lines:
        if row[0] == book_name:
            row[2] = str(int(row[2]) + 1)
            print("还书成功！")
            break

    with open(books_csv_path, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(lines)
