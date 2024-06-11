#include <stdio.h>
double per(int i){
	if (i<=10){
		return i * 0.1;
	}
	else if (i>10&&i<=20){
	return 	i * 0.1 + (20-i) * 0.75;
	}
	else if (i>20&&i<=40){
	return (i-20)*0.05;
	} 
	else if (i>40&&i<=60){
	return	(i-40)*0.03;
	}
	else if (i>60&&i<=100){
	return (i-60)*0.015;
	}
	else{
		return (i-100)*0.01;
	}
}
int main(){
	int a;
	scanf("%d",&a);
	double b=per(a)*10000;
	printf("奖金是 %d\n",b);
}