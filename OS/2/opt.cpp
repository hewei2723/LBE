// //最佳页面置换算法
// //因为程序的大小和内存的大小关系，有时候并不能给程序一次性全部调入内存
// //就会给内存分成几个部分，每次只能将一部分调入内存，这就是分页
// //例题有三个物理块 block[3] ，初始为空
// //有这几个页面引用7 0 1 |2 0 3| 0 4 2| 3 0 3| 2 1 2| 0 1 7| 0 1
// //每次只能将一个页面调入内存，当内存满时，需要将一个页面调出内存，将新页面调入内存,调出的页面是最久未使用的页面
// //即：当内存满时，将内存中最早调入的页面调出，将新页面调入内存
// /*
// 7 block[0]=7    7 0 0 
// 0 block[1]=0    7 0 0
// 1 block[2]=1    7 0 1
// ------------------
// 2 block[0]=2    2 0 1
// 0 内存里面已经有了，不用换
// 3 block[2]=3    2 0 3
// ------------------
// 0 内存里面已经有了，不用换
// 4 block[1]=4    2 4 3
// 2 内存里面已经有了，不用换
// ------------------
// 3 内存里面已经有了，不用换
// 0 block[1]=0    2 0 3
// 3 内存里面已经有了，不用换
// ------------------
// 2 内存里面已经有了，不用换
// 1 block[2]=1    2 0 1
// 2 内存里面已经有了，不用换
// ------------------
// 0 内存里面已经有了，不用换
// 1 内存里面已经有了，不用换
// 7 block[0]=7    7 0 1
// ------------------
// 0 
// 1 内存里面已经有了，不用换
//  */
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;
// vector<int> block = {0, 0, 0}; 
// int MaxNum;
// vector<int> page = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
// typedef struct {
//     int page;
//     int max;
//     int poi;
// }pages;
// vector<pages> pageTemp;
// //首先看当前页号在不在物理块里面
// //如果在，则不用换
// //如果不在，那么给最久未使用的或以后都不用的换掉
// //从当前位置遍历，找到最久未使用的页号（距离当前位置最远的），然后换掉距离当前最远的数据所在块号，换成当前的页号
// void ShowBlock(){
//     cout<<block[0]<<" "<<block[1]<<" "<<block[2]<<"\n";
// }
// int main()
// {
//     for(int i=0;i<3;i++)
//     {
//        block[i]=page[i]; 
//     }
//     for(int i=3;i<page.size();i++)
//     {
//         int count;
//         int pageT;
//         for (int j= 0; j < 3; j++)
//         {
//             if(page[i]==block[j]){
//                 ShowBlock();
//             }else{
//                int a=i+1;
//                for(int k=a;k<page.size();k++){
//                 if(page[k]==block[j]){//如果找到了。那说明当前位置就是哪个最远的位置
//                 pageTemp[j].page=page[i];
//                 pageTemp[j].max=count;
//                 pageTemp[j].poi=j;
//                 count=0;
//                 }else{
//                     //没找到，计数器+1
//                     count++;
//                 }
//                }
//             }
//         }
//         MaxNum=max(pageTemp[0].max,max(pageTemp[1].max,pageTemp[2].max));
//         for(int s=0;s<3;s++){
//             if(MaxNum==pageTemp[s].max){
//                 pageT=pageTemp[s].poi;//要换掉的序号
//             }
//         }
//         block[pageT]=page[i];
//         ShowBlock();
//     }
// }
#include <iostream>
#include <vector>
#include <algorithm>  // 用于 std::max

using namespace std;

vector<int> block = {0, 0, 0};  // 物理块
int count = 0, MaxNum;
vector<int> page = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};  // 页面引用序列

typedef struct {
    int page;  // 页面编号
    int max;   // 最大距离
    int poi;   // 被替换的物理块
} pages;

vector<pages> pageTemp(3);  // 初始化大小为 3 的 pageTemp 数组

void ShowBlock() {
    cout << block[0] << " " << block[1] << " " << block[2] << "\n";
}

int main() {
    // 初始化前三个页面到物理块
    for (int i = 0; i < 3; i++) {
        block[i] = page[i];
        ShowBlock();
    }
    ShowBlock();  // 输出初始物理块状态

    // 从第 3 个页面开始处理
    for (int i = 3; i < page.size(); i++) {
        bool pageFound = false;

        // 检查当前页面是否已经在物理块中
        for (int j = 0; j < 3; j++) {
            if (page[i] == block[j]) {
                // 页面已存在，不做替换，直接输出当前物理块
                pageFound = true;
                ShowBlock();
                break;
            }
        }

        if (!pageFound) {
            // 页面不在物理块中，需要替换
            // 遍历物理块并计算每个页面的 "最远使用时间"
            for (int j = 0; j < 3; j++) {
                int a = i + 1;  // 当前位置的后续页面
                bool found = false;
                pageTemp[j].max = 0;  // 重置最大距离

                for (int k = a; k < page.size(); k++) {
                    if (page[k] == block[j]) {  // 如果找到了该页面，表示它之后还会使用
                        pageTemp[j].max = k - i;  // 记录距离当前位置的最大距离
                        found = true;
                        break;
                    }
                }

                // 如果该页面没有在后续被使用（最远未使用的页面）
                if (!found) {
                    pageTemp[j].max = 99999;  // 标记为一个很大的数字，表示永远不被使用
                }

                // 更新页面信息
                pageTemp[j].page = block[j];
                pageTemp[j].poi = j;
            }

            // 找到最久未使用的页面并替换
            MaxNum = max(pageTemp[0].max, max(pageTemp[1].max, pageTemp[2].max));
            int pageT = -1;
            for (int s = 0; s < 3; s++) {
                if (MaxNum == pageTemp[s].max) {
                    pageT = pageTemp[s].poi;  // 记录要替换的物理块
                    break;
                }
            }

            // 替换页面
            block[pageT] = page[i];
            ShowBlock();
        }
    }

    return 0;
}
