from typing import List
from collections import defaultdict

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjlist = defaultdict(list)
        for edge in edges:
            u = edge[0]
            v = edge[1]
            adjlist[u].append(v)
            adjlist[v].append(u)

        seen = set()
        def dfs(node):
            seen.add(node)
            for n in adjlist[node]:
                if n not in seen:
                    dfs(n)

        count = 0
        for k in range(n):
            if k not in seen:
                dfs(k)
                count+=1

        return count

if __name__ == "__main__":
    n = 5
    edges = [[0,1],[1,2],[3,4]]
    sol = Solution()
    print(sol.countComponents(n, edges)) 
