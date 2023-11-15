int maximizeSum(int* nums, int numsSize, int k){
    int m=0;
    for (int i=0;i < numsSize;i++){
      m =fmax(m,nums[i]);
    }
  return (2*m+k-1)*k/2;
}
//在第一次出现时找最大的那一个值，然后等差公式an+1==a1+k