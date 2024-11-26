//先来先服务
#include <iostream>
#include <vector>
struct process
{
    int id;
    int arrive_time;
    int burst_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};
int main()
{
    int n;
    std::cout << "请输入进程数量：";
    std::cin >> n;
    std::vector<process> processes(n);
    for (int i = 0; i < n; i++)
    {
        std::cout << "请输入进程" << i + 1 << "的到达时间、执行时间："; //输入进程的到达时间和执行时间
        std::cin >> processes[i].arrive_time >> processes[i].burst_time;
        processes[i].id = i + 1;
    }
}