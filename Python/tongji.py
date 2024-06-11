import os
import fileinput
import tkinter as tk
from tkinter import messagebox

# 代码行数统计函数
def count_code_lines(file_path):
    with open(file_path, encoding='utf-8', errors='ignore') as file:
        return sum(1 for line in file if line.strip() and not line.strip().startswith("#"))

def count_code_lines_in_folder(folder_path):
    total_lines = 0
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith(".py"):  # 只考虑Python代码文件
                file_path = os.path.join(root, file)
                total_lines += count_code_lines(file_path)
    return total_lines

# 创建图形界面
def show_code_stats():
    folder_path = entry_folder_path.get()
    total_lines = count_code_lines_in_folder(folder_path)
    result_message = f"总共写了这么多行代码不包括注释换行: {total_lines}"
    messagebox.showinfo("Code Statistics", result_message)

# 主窗口
root = tk.Tk()
root.title("Code Stats")

# 输入文件夹路径的文本框
label_folder_path = tk.Label(root, text="文件夹")
label_folder_path.pack()

entry_folder_path = tk.Entry(root, width=50)
entry_folder_path.pack()

# 统计按钮
button_stat = tk.Button(root, text="统计", command=show_code_stats)
button_stat.pack()

# 运行图形界面
root.mainloop()
