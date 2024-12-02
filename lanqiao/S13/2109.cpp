#include<iostream>
using namespace std;
int n=3,m=4,k=10;
int main(){
    // cin>>n>>m>>k;
    int t[n][m]={1,2,3,4,5,6,7,8,9,10,11,12};
    //遍历矩阵从0到n,从0到m
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cout<<t[x][y]<<" ";
        }
        cout<<"\n";
    }
    }
