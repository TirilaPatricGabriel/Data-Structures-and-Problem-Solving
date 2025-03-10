class Solution:
    def climb(self, n: int, cur: int, memo) -> int:
        if cur == n:
            return 1
        
        if cur > n:
            return 0

        if cur in memo:
            return memo[cur]

        memo[cur] = self.climb(n, cur+1, memo) + self.climb(n, cur+2, memo)

        return memo[cur]

    def climbStairs(self, n: int) -> int:
        return self.climb(n, 0, {})