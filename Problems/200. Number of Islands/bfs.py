from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        islands = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    islands += 1
                    q = deque()
                    q.append((i, j))
                    while q:
                        row, col = q.popleft()

                        for dx, dy in dirs:
                            nx, ny = row + dx, col + dy
                            if nx >= 0 and nx < len(grid) and ny >= 0 and ny < len(grid[0]) and grid[nx][ny] == "1":
                                grid[nx][ny] = "0"
                                q.append((nx, ny))
        
        return islands





        