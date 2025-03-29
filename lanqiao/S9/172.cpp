#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,a1,b1,c1,count=0;
    vector<int>a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a1;
        a.push_back(a1);
    }
    for(int i=0;i<n;i++){
        cin>>b1;
        b.push_back(b1);
    }
    for(int i=0;i<n;i++){
        cin>>c1;
        c.push_back(c1);
    }
    for(int na:a){
        for(int nb:b){
            for(int nc:c){
                if(na<nb&nb<nc){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}