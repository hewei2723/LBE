def 重复字(lst):
    res = []
    seen = set()
    for num in lst:
        if num not in seen:
            res.append(num)
            seen.add(num)
    return res

input_list = [1, 2, 4]
result = 重复字(input_list)
print(''.join(map(str, map(int, result))))