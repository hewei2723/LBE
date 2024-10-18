#include <stdio.h>

// 函数：判断一个数是否为“好数”
int isGoodNumber(int num) {
    int position = 1; // 从个位开始，位置从 1 开始
    while (num > 0) {
        int digit = num % 10;
        if (position % 2 == 1) { // 奇数位
            if (digit % 2 == 0) {
                return 0; // 不满足条件
            }
        } else { // 偶数位
            if (digit % 2 != 0) {
                return 0; // 不满足条件
            }
        }
        num /= 10;
        position++;
    }
    return 1; // 满足所有位的条件
}

int main() {
    int N;
    scanf("%d", &N);
    
    int count = 0;
    for (int num = 1; num <= N; num++) {
        if (isGoodNumber(num)) {
            count++;
        }
    }
    
    printf("%d", count);
    return 0;
}
