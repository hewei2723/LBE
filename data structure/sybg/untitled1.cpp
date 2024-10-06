#include <stdio.h>
int main(){
	int num=1234,a,b,c,d;
	a=num%10;
	b=num/100%10;
	c=num/10%10;
	d=num/1000;
	printf("%d%d%d%d",&a,&b,&c,&d);
}
