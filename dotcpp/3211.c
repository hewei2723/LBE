#include <stdio.h>
#include <math.h>
int lcm(int a, int b,int c){
    int lcm = a*b*c;
    while(1){
        if(a%c==0 && b%c==0){
            return lcm;
        }
        lcm++;
    }
}
int main(){
    int n,i;
    float m[i];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%f",&m[i]);
    }
    

}