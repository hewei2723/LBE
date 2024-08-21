#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking（邪恶的浮点数位运算黑科技）
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?（这是什么鬼？）
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration （第一次迭代）
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed（第二次迭代，可以删除）

	return y;
}
int main(){
    float x = 1.0;
    printf("%f\n",Q_rsqrt(x));
    return 0;
}