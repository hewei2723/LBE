public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        // 创建一个字典用于存储每个元素对应的索引
        Dictionary<int, int> numDict = new Dictionary<int, int>();
        
        // 遍历数组
        for (int i = 0; i < nums.Length; i++) {
            // 计算目标值与当前值的差
            int complement = target - nums[i];
            // 检查差值是否在字典中
            if (numDict.ContainsKey(complement)) {
                // 如果找到了差值，返回对应的索引
                return new int[]{numDict[complement], i};
            }
            // 如果没有找到差值，将当前值添加到字典中
            numDict[nums[i]] = i;
        }

        // 如果没有找到符合条件的元素，返回空数组
        return new int[0];
    }
}