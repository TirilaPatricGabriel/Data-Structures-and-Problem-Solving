class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0

        if nums[1] < nums[0]:
            return 0
        
        if nums[len(nums)-2] < nums[len(nums)-1]:
            return len(nums)-1
        
        left = 0
        right = len(nums)-1

        while True:
            mid = (left+right) // 2
            el = nums[mid]
            if nums[mid-1] < el and nums[mid+1] < el:
                return mid
            if nums[mid-1] > el:
                right = mid-1
            else:
                left = mid+1
         
            
