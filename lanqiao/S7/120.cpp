/*
随机抽查，先排序
算等比数列，中间会有未知值，也能当前就是名字排序
求最大可能等比
等比公式q a[n+1]/a[n]=q
3
1250 200 32
25/4 6.25
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct nums
{
    int a,b;
    float c;
}nums;

int comp(int a,int b){
    return a>b;
}
int compNums( nums &a,nums b){
    return a.c>b.c;
}
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void re(int &son,int &mom){
    int c=gcd(son,mom);
    son=son/c;
    mom=mom/c;
}
int main()
{
  int n,tn;
  vector<int>num;
  vector<nums> numvec;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>tn;
    num.push_back(tn);
  }
  sort(num.begin(),num.end(),comp);
  //排序了最大的放到了最前面，最小的在最后面，不超过100个数，两两相比，找最大
  for(int i=0;i<num.size()-1;i++){
    float temp_num=num[i]/num[i+1];
    nums temp_nums={num[i],num[i+1],temp_num};
    numvec.push_back(temp_nums);
  }
  sort(numvec.begin(),numvec.end(),compNums);
  re(numvec[0].a,numvec[0].b);
  cout<<numvec[0].a<<"/"<<numvec[0].b;
  return 0;
}