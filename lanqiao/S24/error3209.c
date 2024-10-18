#include <stdio.h>
int main()
{
    int n=1, num,a=0;
    scanf("%d",&num);
    while (a < num)
    {
        if (n < 5)
        {
            a=2*n-1;
        }
        else if (n >= 5)
        {
            a=2*n+11;
        }    
        n++;   
    }
    printf("%d",n);
}