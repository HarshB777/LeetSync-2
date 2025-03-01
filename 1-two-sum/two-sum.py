class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        tracker = {}

        for i,_ in enumerate(nums):
            diff = target - _
            if diff in tracker:
                return [tracker.get(diff), i]
            tracker[_] = i
        
        return []
        