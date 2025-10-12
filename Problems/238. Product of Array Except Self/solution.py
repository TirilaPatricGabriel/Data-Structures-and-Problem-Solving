class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_prod = []
        suffix_prod = []

        prefix_prod = [1]
        suffix_prod = [1]

        for left in range(1, len(nums)):
            right = len(nums) - left - 1

            prefix_prod.append(nums[left-1] * prefix_prod[-1])
            suffix_prod.append(nums[right+1] * suffix_prod[-1])

        suffix_prod.reverse()

        res_arr = [a*b for a, b in zip(prefix_prod, suffix_prod)]

        return res_arr