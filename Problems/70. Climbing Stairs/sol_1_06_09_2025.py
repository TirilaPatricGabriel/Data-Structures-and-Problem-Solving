class Solution:
    def climbStairs(self, n):
        memo = {}

        def helper(n):
            if n <= 2:
                return n

            if n in memo:
                return memo[n]

            res = helper(n-1) + helper(n-2)
            memo[n] = res

            return memo[n]

        return helper(n)

class Solution:
    def climbStairs(self, n):
        if n <= 2:
            return n

        dp = [0] * (n+1)

        dp[1] = 1
        dp[2] = 2

        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]

        return dp[n]
