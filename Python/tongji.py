import os
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
folder_path = "E:\lbe\Python"
total_lines = count_code_lines_in_folder(folder_path)
print(f"总共写了这么多行代码不包括注释换行: {total_lines}")
