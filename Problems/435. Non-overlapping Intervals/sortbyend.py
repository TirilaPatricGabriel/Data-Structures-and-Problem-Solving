class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        
        cur_int = intervals[0]

        cnt = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < cur_int[1]:
                cnt += 1
            else:
                cur_int = intervals[i]

        return cnt