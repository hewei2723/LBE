#include <iostream>
#include <vector>
using namespace std;
int main(){
    int i,sum,num=0;
    for (int i=1;i<=40;i++){
    sum=i;
    while(sum){
    num++;
    cout<<num<<" ";
    sum--; 
    }
    cout<<i<<"\n";
    }
}
