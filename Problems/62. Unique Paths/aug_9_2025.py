class Solution:
    def solveProblemRecursively(self, pos: tuple, end: tuple) -> int:
        if pos == end:
            return 1
        
        if pos[0] > end[0] or pos[1] > end[1]:
            return 0
        
        return self.solveProblemRecursively((pos[0] + 1, pos[1]), end) + self.solveProblemRecursively((pos[0], pos[1] + 1), end)
 
    def solveProblemWithMemoization(self, pos, end, memo):
        if (pos, end) in memo:
            return memo[(pos, end)]
        
        if pos == end:
            memo[(pos, end)] = 1
            return 1
        
        if pos[0] > end[0] or pos[1] > end[1]:
            memo[(pos, end)] = 0
            return 0
        
        result = (self.solveProblemWithMemoization((pos[0]+1, pos[1]), end, memo)) + (self.solveProblemWithMemoization((pos[0], pos[1]+1), end, memo))
        memo[(pos, end)] = result

        return result        

    def solveProblemWithDP(self, m, n) -> int:
        dp = [[1] * n for _ in range(m)]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]

        return dp[m-1][n-1]

    def uniquePaths(self, m: int, n: int) -> int:
        pos = (0, 0)
        end = (m-1, n-1)
        memo = {}
        
        print(self.solveProblemRecursively(pos, end))
        print(self.solveProblemWithMemoization(pos, end, memo))
        print(self.solveProblemWithDP(m, n))


def main():
    solution = Solution()

    solution.uniquePaths(3, 7)

if __name__ == '__main__':
    main()