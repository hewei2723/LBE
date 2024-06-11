# 计算最长公共前缀数组
def compute_lps_array(pat):
    M = len(pat)
    lps = [0] * M
    length = 0  # 当前最长前缀长度
    i = 1

    while i < M:
        if pat[i] == pat[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    
    return lps

# KMP字符串匹配算法
def kmp_search(pat, txt):
    M = len(pat)
    N = len(txt)
    lps = compute_lps_array(pat)
    i = 0  # 主串索引
    j = 0  # 模式串索引

    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1
        
        if j == M:
            print(f"Found pattern at index {i - j}")
            j = lps[j - 1]
        elif i < N and pat[j] != txt[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

# 测试代码
txt = "ABAABABCAB"
pat = "ABABCAB"
kmp_search(pat, txt)