#include <iostream>
using namespace std;
// 时间戳转换
// 60s=1min
// 60min=1h 3600s
// 7200s=120min=2h
// 24h=1day

int main()
{
    long long second, time;
    int h, m, s;
    time = 1618708103123; // 1618708103s
    second = time / 1000;
    s = second % 60;
    m = (second % 3600)/60;
    h = (second / 3600) % 24;
    if(h<10){
        cout<<0<<h<<":";
    }else{
        cout<<h<<":";
    }
        if(m<10){
        cout<<0<<m<<":";
    }else{
        cout<<m<<":";
    }
        if(s<10){
        cout<<0<<s;
    }else{
        cout<<s;
    }
    
    
}