class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        h = {}

        for n in nums:
            if n in h:
                return True
            h[n] = True

        return False