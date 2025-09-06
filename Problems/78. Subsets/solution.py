class Solution:
    def subsets(self, nums):
        res = []
        
        def bt(curr, start):
            res.append(curr[:])  
            
            for i in range(start, len(nums)):
                curr.append(nums[i])
                bt(curr, i + 1) 
                curr.pop()
        
        bt([], 0)
        return res

