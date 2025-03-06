#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int num1=0;
    int num2=0;
    while(~scanf("%d",&n))
    {
        while(1)
        {
            if(n%2==0)
            {
                num1++;
                n/=2;
            }
            else if(n%5==0)
            {
                num2++;
                n/=5;
            }
            else
                break;
        }
        int num=min(num1,num2);
        printf("%d",num);
    }
    return 0;
}