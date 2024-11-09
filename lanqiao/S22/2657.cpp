/*
爱丽丝要完成一项修剪灌木的工作。有 N 棵灌木整齐的从左到右排成一排。
爱丽丝在每天傍晚会修剪一棵灌木，让灌木的高度变为 0 厘米。
爱丽丝修剪灌木的顺序是从最左侧的灌木开始，每天向右修剪一棵灌木。
当修剪了最右侧的灌木后，她会调转方向，
下一天开始向左修剪灌木。直到修剪了最左的灌木后再次调转方向。
然后如此循环往复。灌木每天从早上到傍晚会长高 1 厘米，而其余时间不会长高。
在第一天的早晨，所有灌木的高度都是 0 厘米。爱丽丝想知道每棵灌木最高长到多高。
*/
// 设置一个数组用来储存晚上的值
// 设置一个数组用来出储存砍掉后的值
#include <iostream>
#include <vector>
using namespace std;
int N, day = 0;
bool flag = 1;
int main()
{
    cin >> N; // N棵树
    vector<int> tree(N, 0);
    // 累计天数
    for (int j = 0; j < N * 3; j++)
    {
        for (int i = 0; i < N; i++)
        {
            tree[i] = tree[i] + 1;
        } // 给所有树都增高
        // 从左到右从0增到N，当day%N等于0的时候就是一个循环
        if (day % N == 0)
        {
            flag = ~flag;
        }
        if (flag == 1)
        { // 第一次为1，正向
        tree[day%N]=0;//tree 0 1 2 
        }
        else
        { // 然后是0，反向
        tree[day%N]=0;//tree 1 0
        }
        day++;
        for (int k = 0; k < N; k++)
        {
            cout << tree[k] << ' ';
        }
        cout << "\n";
    }
}