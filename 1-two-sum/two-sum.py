class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hm = {}
        n = len(nums)
        ans = []
        for i in range(n):
            fin = target - nums[i]

            if fin in hm:
                ans.append(hm[fin])
                ans.append(i)
                break
            
            hm[nums[i]] = i
        
        return ans

