class Solution:
    def res(self, i: int, j: int, m: int, n: int, memo) -> int:
        if i >= m or j >= n:
            return 0

        if i == m-1 and j == n-1:
            return 1

        if (i, j) in memo:
            return memo[(i, j)]

        memo[(i, j)] = self.res(i, j+1, m, n, memo) + self.res(i+1, j, m, n, memo)

        return memo[(i, j)]

    def uniquePaths(self, m: int, n: int) -> int:
        return self.res(0, 0, m, n, {})