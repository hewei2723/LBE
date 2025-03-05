#include <iostream>
using namespace std;
int main()
{
//1 +2 3 +3 6 +4 10
int num=0,sum=0;
for(int i=1;i<=100;i++){
    num=num+i;
    sum=sum+num;
}
cout<<sum;
  return 0;
}