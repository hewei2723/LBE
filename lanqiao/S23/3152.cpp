/*对于一个长度为 K 的整数数列：A1, A2, . . . , AK，
我们称之为接龙数列当且仅当 Ai 的首位数字恰好等于 Ai−1 的末位数字 (2 ≤ i ≤ K)。
例如 12, 23, 35, 56, 61, 11 是接龙数列；12, 23, 34, 56 不是接龙数列，
因为 56的首位数字不等于 34 的末位数字。所有长度为 1 的整数数列都是接龙数列。
现在给定一个长度为 N 的数列 A1, A2, . . . , AN，
请你计算最少从中删除多少个数，可以使剩下的序列是接龙序列？
第一行包含一个整数 N。
第二行包含 N 个整数 A1, A2, . . . , AN。
5
11 121 22 12 2023
1
*/
// 获取每个数字的第一位和最后一位，获取下一个数字的第一位和最后一位
// 如果当前数字的最小位和后一个数字的最大位相同，则正确
// 如果不同，则设置一个计数器计数不符合要求的数字，然后下一位数字往后移
// 直到找到相同的，循环执行
#include <bits/stdc++.h>
using namespace std;
int n,flag,ji=1; // flag作为计数器标志
string tnum;
long long number;
vector<int> num;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        tnum=to_string(number);
        int temp = tnum[0] - '0';// 获取字符串数组的首个元素,就是num[i][0],
        int temp1 = tnum[tnum.size() - 1] - '0'; // 那么获取最后一个元素就是num[i][num[i].size()-1]
        num.push_back(temp);
        num.push_back(temp1);
    }
    while (ji!=num.size()-1)
    {
        if(num[ji]==num[ji+1]){
            ji+=2;
            }
            else{
                flag++;
                ji+=2;
            }
    }
    cout<<flag/2; 
}
