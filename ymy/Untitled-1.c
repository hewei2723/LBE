#include <stdio.h>
int a[5]={2,4,1,89,5};
int main(){
    int min ,i,j,temp;
    for ( i = 0; i < 5; i++)
    {
        min  = a[i];
        for( j = i+1; j<5-i; j++)
        {
            if (a[i]<a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
            
        }
        
    }
    for( i = 0; i < 5; i++)
    {
        printf(" %d",a[i]);
    }
    
   // printf("%d",a[i]);
    
}