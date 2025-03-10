class Solution:
    def solve(self, m:int, n:int, i:int, j:int, memo) -> int:
        if i > m or j > n:
            return 0
        if i == m and j == n:
            return 1

        if (i, j) in memo:
            return memo[(i, j)]
            
        memo[(i,j)] = self.solve(m, n, i+1, j, memo) + self.solve(m, n, i, j+1, memo)
        return memo[(i,j)]

    def uniquePaths(self, m: int, n: int) -> int:
        memo = {}
        return self.solve(m-1, n-1, 0, 0, memo)