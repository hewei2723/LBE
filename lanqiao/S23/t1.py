array = [
    5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5, 8,
    6, 1, 8, 3, 0, 3, 7, 9, 2, 7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5,
    1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 1, 0, 0, 9, 4, 8, 0, 9, 1,
    2, 8, 5, 0, 2, 5, 3, 3
]

valid_dates = set()

for i in range(len(array) - 7):
    # 取出长度为8的子序列
    sub_seq = array[i:i + 8]
    # 组成日期字符串
    date_str = ''.join(map(str, sub_seq))
    
    # 分割为 yyyy, mm, dd
    year = date_str[:4]  # 2023
    month = int(date_str[4:6])
    day = int(date_str[6:8])
    
    # 检查日期的有效性
    if year == '2023':
        if month < 1 or month > 12:
            continue  # 无效的月份
        if month in {1, 3, 5, 7, 8, 10, 12} and 1 <= day <= 31:
            valid_dates.add(date_str)
        elif month in {4, 6, 9, 11} and 1 <= day <= 30:
            valid_dates.add(date_str)
        elif month == 2 and 1 <= day <= 28:
            valid_dates.add(date_str)

# 输出不同有效日期的数量
print(len(valid_dates))
