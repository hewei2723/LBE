/*
找出b[i]>a[i]的次数
找出b[i]<c[i]的次数
排序a,c
*/
#include <bits/stdc++.h>
using namespace std;
int find(int a){
    
}
int main()
{
    int n = 3, ct, num, a[n], b[n], c[n];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    };
    sort(a, a + n);
    for (int i = 0; i < 3; i++)
    {
        cin >> b[i];
    }
    sort(b, b + n);
    for (int i = 0; i < 3; i++)
    {
        cin >> c[i];
    }
    sort(c, c + n);
    return 0;
}