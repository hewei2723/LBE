/*
随机抽查，先排序
算等比数列，中间会有未知值，也能当前就是名字排序
求最大可能等比
等比公式q a[n+1]/a[n]=q
3
1250 200 32
25/4 6.25
*/
#include<bits/stdc++.h>
using namespace std;
int comp(int a,int b){
    return a>b;
}
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void re(int a,int b){
    int c=gcd(a,b);
    a=a/c;
    b=b/c;
}
int main()
{
  // 请在此输入您的代码
  int n=3;
  vector<int>num={1250,200,32};
  sort(num.begin(),num.end(),comp);
  return 0;
}