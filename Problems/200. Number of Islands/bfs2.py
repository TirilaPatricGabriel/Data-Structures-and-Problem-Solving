from collections import deque
from typing import List

class Solution:
    dirs = [(-1, 0), (0, -1), (0, 1), (1, 0)]

    def expandIsland(self, i, j, seen, grid):
        dq = deque()
        dq.append((i, j))
        seen.add((i, j))

        while dq:
            x, y = dq.popleft()  

            for dx, dy in self.dirs:
                nx, ny = x + dx, y + dy
                if (
                    0 <= nx < len(grid)
                    and 0 <= ny < len(grid[0])
                    and grid[nx][ny] == "1"
                    and (nx, ny) not in seen
                ):
                    seen.add((nx, ny))
                    dq.append((nx, ny))

    def numIslands(self, grid: List[List[str]]) -> int:
        n = 0
        seen = set()

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1" and (i, j) not in seen:
                    n += 1
                    self.expandIsland(i, j, seen, grid)

        return n
