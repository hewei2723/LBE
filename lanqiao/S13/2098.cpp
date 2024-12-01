/*
小明决定从下周一开始努力刷题准备蓝桥杯竞赛。他计划周一至周五每天做 
a 道题目, 周六和周日每天做 b 道题目。请你帮小明计算, 按照计划他将在 第几天实现做题数大于等于 n
10 20 99
8

5*10+20+20+10=100
*/
#include<iostream>
using namespace std;
long long day,sum,a,b,n;
int main(){
    cin>>a>>b>>n;
    while(sum<n){
    for(int i=0;i<6;i++){
       sum+=a;
       day++; 
    }
    for(int j=0;j<2;j++){
        sum+=b;
        day++;
    }
    }
    cout<<day;
    return 0;
}