#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main() {
    int n,p,q,power=0,eneger=0;
    cin>>n>>p>>q;
    vector<int> a(n);
    priority_queue<int> pw;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pw.push(a[i]);//将数字推入堆中
        }
    for (int i = 0; i < p; i++)
    {
        power=pw.top();//取出堆顶元素
        pw.pop();//删除堆顶元素
        pw.push(sqrt(power));//将堆顶元素开平方后推入堆中后推入堆中
        //p次操作后完成削弱
    }
    for (int i = 0; i < q; i++)
    {
        /* code */
        power=pw.top();//取出堆顶元素
        pw.pop();//删除堆顶元素
        pw.push(power*0.5);//将堆顶元素乘2后推入堆中
        //q次操作后完成削弱
    }
    while(!pw.empty()){
        eneger+=pw.top();
        pw.pop(); 
    }
    cout<<eneger<<endl;
}