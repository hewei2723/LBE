#include <iostream>
using namespace std;
int main(){
    int begin,end,yearB,yearE,monthB,monthE,dayB,dayE;
    cin>>begin;
    cin>>end;
    yearB = begin / 10000;
    yearE = end / 10000;
    monthB = (begin % 10000) / 100;
    monthE = (end % 10000) / 100;
    dayB = begin % 100;
    dayE = end % 100;
    for(int iy=yearB;iy<=yearE;iy++){
        for(int im=monthB;im<=monthE;im++){
            for(int id=dayB;id<=dayE;id++){
                cout<<iy*10000+im*100+id<<endl;
            }
        }
    }
}