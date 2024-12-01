#include<iostream>
using namespace std;
int main(){
    //20220123
    for(int m=1;m<13;m++){
        for (int day = 1; day < 32; day++)
        {
            if(m<10&&day<10){
                cout<<20220<<m<<0<<day<<"\n";
            }else
            if(m<10&&day>=10){
                cout<<20220<<m<<day<<"\n";
            }else
            if (m>=10&&day<10)
            {
                cout<<2022<<m<<0<<day<<"\n";
            }else{
                cout<<2022<<m<<day<<"\n";
            }           
        }
    }
}