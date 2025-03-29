#include <iostream>
/*
一个谜语对应多个灯笼，一个灯笼可以对应多个谜语
当后一个谜语的第一个灯笼位于前一个谜语的灯笼区间内时
直接访问后一个灯笼的第一个灯笼
*/
using namespace std;
int main()
{
    int n,m;//n 灯笼的数量 m 谜语的数量
    cin>>n>>m;
    int l[n],r[n],xy[n];
    for (int i = 0; i < m; i++)
    {
        cin>>l[i]>>r[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (l[i+1]>=l[i]&&l[i+1]<=r[i])//如果后一个谜语的第一个灯笼位于前一个谜语的灯笼区间内
        {
            xy[i]=l[i+1];
        }
        
    }
    
    
    return 0;
}