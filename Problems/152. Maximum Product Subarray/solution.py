class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxnr = max(nums)
        cmin, cmax = 1, 1

        for n in nums:
            if n != 0:
                temp = cmax
                cmax = max(n, n * cmax, n * cmin)
                cmin = min(n, n * temp, n * cmin)
                maxnr = max(maxnr, cmax)
            else:
                cmin, cmax = 1, 1

        return maxnr