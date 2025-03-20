class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 1

        k = 0
        c = 0

        for j in range(1, len(nums)):
            if nums[k] != nums[j]:
                nums[k+1] = nums[j]
                k+=1

        return k+1