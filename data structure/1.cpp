#include <iostream>
using namespace std;
// 定义顺序表的最大长度1
#define MAXSIZE 5
// 定义顺序表类型
typedef int ElemType;
// 定义顺序表结构
struct SqList {
  ElemType data[MAXSIZE];
  int length;
};
// 初始化顺序表
void InitList(SqList &L) { L.length = 0; }
// 插入元素
void InsertElem(SqList &L, int i, ElemType e) {
  if (i < 0 || i > L.length) return;
  for (int j = L.length - 1; j >= i; j--) L.data[j + 1] = L.data[j];
  L.data[i] = e;
  L.length++;
}
// 删除元素
void DeleteElem(SqList &L, int i) {
  if (i < 0 || i >= L.length) return;
  for (int j = i + 1; j < L.length; j++) L.data[j - 1] = L.data[j];
  L.length--;
}
// 打印顺序表
void PrintList(SqList L) {
  for (int i = 0; i < L.length; i++) cout << L.data[i] << " ";
  cout << endl;
}
int main() {
  SqList L;
  InitList(L);
  // 插入元素
  InsertElem(L, 0, 1);
  InsertElem(L, 1, 2);
  InsertElem(L, 2, 3);
  // 打印顺序表
  PrintList(L);
  // 删除元素
  DeleteElem(L, 1);
  // 打印顺序表
  PrintList(L);
  return 0;
}
