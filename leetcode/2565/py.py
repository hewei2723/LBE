class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
      #找最大的那个数,然后求d为的前k项和
      self = max(nums)
      return k*(2*self+k-1)//2