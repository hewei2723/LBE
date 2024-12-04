#include <vector>
vector<int> TrackOrder; //磁道初始序列 在函数中简写为 t
vector<int> MoveDistance; //磁头移动距离 在函数中简写为 d
vector<int> List;  //磁道访问序列 在函数中简写为 list
double AverageDistance; //平均寻道距离
int begin; //初始磁道数
bool Direction; // 磁头移动方向
void FCFS(vector<int> t, vector<int> &list, vector<int> &d, int begin){
    int length = t.size();
    int cur = begin; // 当前磁道数
    for(int i = 0; i < length; i ++){
        list.push_back(t[i]);
        d.push_back(abs( cur - list[i] ));
        cur = list[i];
    }
}