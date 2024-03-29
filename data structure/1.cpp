#include <iostream>

using namespace std;

// 定义顺序表的最大长度
#define MAXSIZE 100

// 定义顺序表类型
typedef int ElemType;

// 定义顺序表结构
struct SqList {
  // 存储元素的数组
  ElemType data[MAXSIZE];
  // 顺序表的长度
  int length;
};

// 初始化顺序表
void InitList(SqList &L) {
  // 将顺序表的长度置为0
  L.length = 0;
}

// 判断顺序表是否为空
bool IsEmpty(SqList L) {
  // 顺序表的长度为0则为空
  return L.length == 0;
}

// 获取顺序表的长度
int GetLength(SqList L) {
  // 返回顺序表的长度
  return L.length;
}

// 插入元素
void InsertElem(SqList &L, int i, ElemType e) {
  // i > L.length 表示插入位置不合法
  if (i < 0 || i > L.length) {
    return;
  }
  // 从i位置开始，将所有元素向后移动一位
  for (int j = L.length - 1; j >= i; j--) {
    L.data[j + 1] = L.data[j];
  }
  // 将要插入的元素放在i位置
  L.data[i] = e;
  // 顺序表的长度加1
  L.length++;
}

// 删除元素
void DeleteElem(SqList &L, int i) {
  // i > L.length 表示删除位置不合法
  if (i < 0 || i >= L.length) {
    return;
  }
  // 从i位置开始，将所有元素向前移动一位
  for (int j = i + 1; j < L.length; j++) {
    L.data[j - 1] = L.data[j];
  }
  // 顺序表的长度减1
  L.length--;
}

// 遍历顺序表
void PrintList(SqList L) {
  // 从第一个元素开始，依次输出每个元素
  for (int i = 0; i < L.length; i++) {
    cout << L.data[i] << " ";
  }
  cout << endl;
}

int main() {
  // 创建一个顺序表
  SqList L;
  // 初始化顺序表
  InitList(L);

  // 插入元素
  InsertElem(L, 0, 1);
  InsertElem(L, 1, 2);
  InsertElem(L, 2, 3);

  // 遍历顺序表
  PrintList(L);

  // 删除元素
  DeleteElem(L, 1);

  // 遍历顺序表
  PrintList(L);

  return 0;
}
