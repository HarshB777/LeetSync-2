class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        se = set()

        for num in nums:
            if num in se:
                return True
            se.add(num)
        
        return False
        