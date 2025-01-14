#include <iostream>
using namespace std;
#include <stdio.h> 
int gcd(int a,int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
    return a;
}

int  main(){
    int sum=0;
    for (int i=1;i<=2020;i++){
        for (int j=1;j<=2020;j++){
            if(gcd(i,j)==1){
                sum++;
            }
            
        }
    }
    cout<<sum;
}