class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        hm = {}

        for i in range(n):
            diff = target - nums[i]
            if (hm.get(diff) != None):
                return [i, hm[diff]]
            
            hm[nums[i]] = i


        return [1]
        