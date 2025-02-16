#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){
  if(a<=b){
    return a;
  }else
  {
    return b;
  }
}
int m(int N,int S,int T ){
  int Sz=0,So=0,Tz=0,To=0;
  for(int i=0;i<N;i++){
    if(S[i]==0){
      Sz++;
    }else
    {
      So++;
    }
  }
  for(int i=0;i<N;i++){
    if(T[i]==0){
      Tz++;
    }else
    {
      To++;
    }
  }
  int c=max(So,Sz)+max(To,Tz);
  return c;
}
int main()
{
  int N;
  int S,T;
  cin>>N>>S>>T;
  int r=m(N,S,T);
  cout<<r;
  return 0;
}