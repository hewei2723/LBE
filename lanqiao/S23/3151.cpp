/*
N 架飞机准备降落到某个只有一条跑道的机场。
其中第 i 架飞机在 Ti 时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 Di 个单位时间，
即它最早可以于 Ti 时刻开始降落，最晚可以于 Ti + Di 时刻开始降落。降落过程需要 Li个单位时间。
一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。
请你判断 N 架飞机是否可以全部安全降落
输入包含多组数据。
第一行包含一个整数 T，代表测试数据的组数。
对于每组数据，第一行包含一个整数 N。
以下 N 行，每行包含三个整数：Ti，Di 和 Li。
3
3
0 100 10
10 10 10
0 2 20
3
0 10 20
10 10 20
20 10 20
4
0 2 10
10 10 20
5 20 10
0 100 10
YES
NO
*/
// 先降落当前最先到达且可盘旋时间最小的，时间加上
// 排列一下所有飞机的到达时间
// 再降落后一架，并判断可盘旋时间 是否 大于上一架飞机的降落时间-减去当前飞机的到达时间，
// 如果可盘旋时间大于，那么继续往后降落，那么不能安全降落
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int t, n, ti, di, li; // t组
vector<bool> result;
typedef struct fly
{
    int ti, di, li;
} fly;
bool compareByTi(const fly &a, const fly &b)
{
    return a.ti < b.ti; // 按到达时间升序排序
}
bool compareByDi(const fly &a, const fly &b)
{
    return a.di < b.di; // 按盘旋时间升序排序
}
// 让到达时间最早且盘旋时间最短的先降落
vector<fly> plane;
int main()
{
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        plane.clear();
        int time = 0;
        cin >> n;//当前组数有多少组
        for (size_t j = 0; j < n; j++)
        {
            fly p;
            cin >> p.ti >> p.di >> p.li;
            plane.push_back(p);
        }
        sort(plane.begin(), plane.end(), compareByTi);
        bool rs;
        for (int k = 0; k < n; k++)
        {
            time = max(time, plane[k].ti); // 防止时间还没到飞机应该到达的时间，同时更新飞机到达的时间
            // 并判断可盘旋时间di 是否 大于上一架飞机的降落时间time-减去当前飞机的到达时间li，
            if (time > plane[k].ti + plane[k].di)
            //如果应该到达时间大于飞机可盘旋的时间，那么就认为飞机的油不足以支持直到飞机降落
            //也就是说，飞机最晚应该是ti+di时到达，而此时计算到达时间time大于最晚到达时间，燃油不够了，失败
            { // 这是不满足的条件，返回false
                // 要求连续输出结果，可以用布尔数组
                rs=0;
                break;
            }
            else
            {
                time += plane[k].li; // 时间更新
                rs=1;
            }
        }
        result.push_back(rs);
    }
    for (int p = 0; p < t; p++)
    {
        if (result[p])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}