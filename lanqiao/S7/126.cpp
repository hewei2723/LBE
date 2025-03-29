//找出最少交换排序次数
//从前往后 记录第i和第i+1的值，只找最小值
//如果如果i<i+1就不动
/*
5
3 1 2 5 4
3 1         1
1 3 2       1 
1 2 3 5
1 2 3 4 5   1
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,index, temp, count = 0,a;
    vector<int> num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        num.push_back(a);
    }
    for(int i=0;i<n;i++){
        while (num[i]!=i+1){//当当前值不等于顺序值
            //num[i]的正确位置应该在num[i]-1的数组的位置上
            index=num[i]-1;
            swap(num[i],num[index]);
            count++;
        }        
    }
    cout<<count;
    return 0;
}