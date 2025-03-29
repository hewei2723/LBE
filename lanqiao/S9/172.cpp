<<<<<<< HEAD
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
=======
/*
找出b[i]>a[i]的次数
找出b[i]<c[i]的次数
排序a,c
*/
#include <bits/stdc++.h>
using namespace std;
int find(int a){
    
}
int main()
{
    int n = 3, ct, num, a[n], b[n], c[n];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    };
    sort(a, a + n);
    for (int i = 0; i < 3; i++)
    {
        cin >> b[i];
    }
    sort(b, b + n);
    for (int i = 0; i < 3; i++)
    {
        cin >> c[i];
    }
    sort(c, c + n);
    return 0;
>>>>>>> f817d5f60ef2060e04b87f9759295f5141c1b046
}