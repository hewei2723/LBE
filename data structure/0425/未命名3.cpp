#include <stdio.h>
int main(){
	int a,b;
	for (a=1;a<10;a++){
		for (b=1;b<=a;b++){
			printf("%d*%d=%d ",a,b,a*b);
		}
		printf("\n");
	}
}
