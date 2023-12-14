`#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   
    int n;
    cin>>n;
    int a[200000],b[200000];
    int k=0,i,j;
    int sum=0;
    for( i=0;i<n;i++)
    {
   
        cin>>a[i];
        sum+=a[i];//将所有数相加
    }
    for( i=0;i<n;i++)//这里a[i]是去掉的数
    {
   
    for(j=0;j<n;j++)
    {
   
        if(2*a[j]==(sum-a[i]))//如果一个数的二倍等于剩下数的和，则是完美的
        {
   
            
           b[k++]=i+1;//这里是i+1，因为要的是位置
           break;
        }
        
    }
    }
    cout<<k<<endl;
    for(i=0;i<k;i++)
        cout<<b[i]