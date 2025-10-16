class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        positions = {}
        left = 0
        curr = maxx = 0
        for i in range(len(s)):
            chrr = s[i]

            if chrr not in positions or positions[chrr] < left:
                positions[chrr] = i
                curr += 1
                maxx = max(curr, maxx)
            else:
                curr = i - positions[chrr]
                left = positions[chrr] + 1
                positions[chrr] = i
        
        return maxx