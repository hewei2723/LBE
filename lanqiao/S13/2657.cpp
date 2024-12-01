/*
爱丽丝要完成一项修剪灌木的工作。有 N 棵灌木整齐的从左到右排成一排。
爱丽丝在每天傍晚会修剪一棵灌木，让灌木的高度变为 0 厘米。
爱丽丝修剪灌木的顺序是从最左侧的灌木开始，每天向右修剪一棵灌木。
当修剪了最右侧的灌木后，她会调转方向，
下一天开始向左修剪灌木。直到修剪了最左的灌木后再次调转方向。
然后如此循环往复。灌木每天从早上到傍晚会长高 1 厘米，而其余时间不会长高。
在第一天的早晨，所有灌木的高度都是 0 厘米。爱丽丝想知道每棵灌木最高长到多高。

输入一个正整数N，输出N行，每行代表最高能长多高
3

4 2 4
1       1
2
1 2 1 2     4
3
1 2	3 2	1 2	3   7 
4
1 2 3 4 3 2 1 2 3 4 10 
5
1 2 3 4 5 4 3 2 1 2 3 4 5 13
6 
1 2 3 4 5 6 5 4 3 2 1 2 3 4 5 6 16 
(n-1)*3+1=3n-3+1=3n-2
*/
#include<iostream>
#include<vector>
using namespace std;
int n,flag=0,high=0;
vector<int> h;
int main(){
    int n=3;
    int tree[n];
    for(int i=1;i<(2*n+1);i++){
        if(i<=3){
            h.push_back(i);
        }
        else{
            if (flag==(n-1))
            {
               flag=-1;
            }
            h.push_back(h[1-flag]);//0 1 2 1-(-1)
            flag++;            
        }
    }
    for (int numi = 0; numi < n; numi++)
    {
        for(int num:h){//num=1 2 3 2 1 
            if(numi!=num){
                tree[numi]=high++;
            }
            
        }
        high=0;
    }
    for(int htree:tree){
        cout<<htree;
    }
    
}