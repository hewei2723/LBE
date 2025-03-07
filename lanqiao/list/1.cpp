#include <bits/stdc++.h>
using namespace std;
int num,n;
vector<int> nums,storg;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        nums.push_back(num);
    };
    sort(nums.begin(),nums.end());
    for(int nn:nums){
        cout<<nn;
    }
    for(int i=nums.size();i>=0;i--){
        cout<<nums[i];
    }
    return 0;
}