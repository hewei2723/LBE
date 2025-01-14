#include <iostream>
using namespace std;
int gcd(int a,int b){
    int c;
    while(b){
        c=a%b;//c是余数,稍后c应该作为除数；
        a=b;//被除数作为除数
        b=c;//余数作为被除数
    }
    return a;
}
int lcm(int a,int b){
    int c;
    c=(a*b)/gcd(a,b);
    return c;
}
int main(){
    int a=4,b=8;
    cout<<gcd(a,b)<<" "<<lcm(a,b);
}
