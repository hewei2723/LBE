#include <stdio.h>
int main(){
    int i,n;
    double k[n];
    int ux[n],uy[n],vx[n],vy[n];
    scanf("%d",&n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d %d %d %d",&ux[i],&uy[i],&vx[i],&vy[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        if(vx[i]!=ux[i] && vy[i]!=uy[i]){
        k[i]=(vy[i]-uy[i])/(vx[i]-ux[i]);
        printf("%f\n",k[i]);
    }
}