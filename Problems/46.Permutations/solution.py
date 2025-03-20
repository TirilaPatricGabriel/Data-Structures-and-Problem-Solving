class Solution:
    def bt(self, nums, res, current, vis):
        if len(current) == len(nums):
            res.append(current)
            return


        for i in range(len(nums)):
            if (nums[i] not in vis) or vis.get(nums[i]) == False:
                vis[nums[i]] = True
                self.bt(nums, res, current + [nums[i]], vis)
                vis[nums[i]] = False

        
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        current = []
        vis = {}
        self.bt(nums, res, current, vis)
        return res