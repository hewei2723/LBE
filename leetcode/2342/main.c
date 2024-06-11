// 定义一个函数，返回两个整数中的较大值
int max(int x, int y){
    return x > y ? x : y;
}

// 主函数，用于计算数组中两个元素各位数字和相等的最大和
int maximumSum(int* nums, int n) {
    // 初始化一个数组，用于存储每个数位和对应的最大值
    int ls[82] = { 0 };
    
    // 初始化变量，用于存储最大和的结果
    int out = -1;

    // 遍历输入数组
    for( int i = 0; i < n; i++ ){
        // 计算当前数字的各位数字和
        int sum = 0;
        for( int tmp = nums[i]; tmp != 0; tmp /= 10 ){
            sum += tmp % 10;
        }

        // 检查当前数位和是否已经存在于数组中
        if( ls[sum] == 0 ){            
            // 如果不存在，将当前元素存储到数组中
            ls[sum] = nums[i];
        }else{
            // 如果存在，更新最大和的结果，并更新数组中的值为较大的元素
            out = max( out, ls[sum] + nums[i] );
            ls[sum] = max( ls[sum], nums[i] );
        }
    }

    // 返回最大和的结果
    return out;
}
