class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        if n == 0 or n == 1:
            return n

        hm = {}
        left = 0

        maxx = 0
        curr = 0

        for i in range(n):
            if s[i] in hm and hm[s[i]] >= left:
                pos = hm[s[i]]
                left = pos + 1
                curr = i - left + 1
            else:
                curr += 1
                maxx = max(maxx, curr)

            hm[s[i]] = i

        return maxx

