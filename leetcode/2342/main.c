int maximumSum(int* nums, int numsSize) {
    for (sum=0;sum<=numsSize;;){
    while (nums[i] != 0) {
        sum += nums[i] % 10; // 取末尾数字
        nums[i] /= 10;       // 去掉末尾数字
    }
    }
}