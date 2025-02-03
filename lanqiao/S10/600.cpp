#include <iostream>
using namespace std;
// 1 1 1 3 5 9 17
int main(){
    long long  sum,num[4]={1,1,1};
    for (int i=1;i<50;i++){
    num[3]=num[0]+num[1]+num[2];
    num[0]=num[1];
    num[1]=num[2];
    num[2]=num[3];
    cout<<num[0]<<" ";
    }
}