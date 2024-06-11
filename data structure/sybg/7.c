#include <stdio.h>

typedef struct {
	int row;
	int col;
	int val;
} THA;

#define MAX 20

int main() {
	int i, j, count;
	int col, row, val;
	THA s[MAX];
	THA t[MAX];
	
	printf("请输入矩阵的行数、列数和非零元素个数: ");
	scanf("%d %d %d", &s[0].row, &s[0].col, &s[0].val);
	if (s[0].val == 0) return 0; /* 无非零元素返回 */
	val = s[0].val;
	
	printf("请输入非零元素的行号、列号和值:\n");
	for (i = 1; i <= val; i++)
		scanf("%d %d %d", &s[i].row, &s[i].col, &s[i].val);
	
	row = s[0].row;
	col = s[0].col;
	count = 1;
	
	for (i = 0; i < col; i++) {
		for (j = 1; j <= val; j++) {
			if (s[j].col == i) {
				t[count].row = s[j].col;
				t[count].col = s[j].row;
				t[count++].val = s[j].val;
			}
		}
	}
	
	t[0].row = col;
	t[0].col = row;
	t[0].val = val;
	
	printf("转置后矩阵存储结构如下：\n");
	for (i = 0; i <= val; i++) {
		printf("%d,%d,%d\n", t[i].row, t[i].col, t[i].val);
	}
	
	return 0;
}