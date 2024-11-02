// 输入共两行。
// 第一行为三个整数 n，P，Q。
// 第二行为 n 个整数 h1，h2，. . . ，hn。
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int getMax();
int main(){
    vector<int> Ni;
    int n,P,Q;
    cin>>n>>P>>Q;
    for(int i=0;i<n;i++){
        cin>>Ni[i];
    }
    for (int i = 0; i < P; i++)
    {
     sort_heap(Ni[0],Ni[n]);
     Ni[n]=sqrt(Ni[n]); 
    }
    for (int i = 0; i < Q; i++)
    {
    sort_heap(Ni[0],Ni[n]);
    Ni[n]=Ni[n]*0.5;   
    }  
}
