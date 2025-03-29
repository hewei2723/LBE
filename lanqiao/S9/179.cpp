#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n,d,k,tts,tid;
  cin>>n>>d>>k;
  vector<int>ts,id;
  for(int i=0;i<n;i++){
    cin>>tts>>tid;
    ts.push_back(tts);
    id.push_back(tid);
  }
  for(int time:ts){
    for(int time1:ts){
        if(abs(time-time1)==d);
        
    }
  }
  return 0;
}