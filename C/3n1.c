#include <stdio.h>
#include <time.h>
void delay(int milliseconds){
    clock_t start_time = clock();
    while(clock() < start_time + milliseconds);
}
int main(){
    int n=2345;
    while(1){
        if (n%2!=0)
        {
            n=3*n+1;
        }
        else{
            n=n/2;
        }
        delay(100); //delay function is not available in C, so we can't use it here
        printf("%d\n",n);
    }
}