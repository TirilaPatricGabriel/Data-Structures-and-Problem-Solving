from typing import List

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # TODO: implement recursive DFS
        pass

# --- Main / Test ---
if __name__ == "__main__":
    n = 5
    edges = [[0,1],[1,2],[3,4]]
    sol = Solution()
    print(sol.countComponents(n, edges))  # Expected: 2
