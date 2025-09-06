class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def bt(curr):
            if len(curr) == len(nums):
                res.append(curr[:])

            for n in nums:
                if n not in curr:
                    curr.append(n)
                    bt(curr)
                    curr.pop()

        bt([])

        return res