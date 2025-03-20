class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        end = len(nums)-1

        while k < end+1:
            if nums[k] == val:
                while end > k and nums[end] == val:
                    end-=1
                if end == k:
                    return k
                
                aux = nums[end]
                nums[end] = nums[k]
                nums[k] = aux
            k+=1
        
        return k
