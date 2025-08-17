from collections import defaultdict

class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        graph = defaultdict(list)
        for edge in edges:
            u, v = edge[0], edge[1]
            graph[u].append(v)
            graph[v].append(u)

        stack = []
        seen = set()
        cnt = 0

        for i in range(n):
            if i not in seen:
                stack.append(i)
                cnt += 1
                seen.add(i)
                while stack:
                    node = stack.pop()
                    for k in graph[node]:
                        if k not in seen:
                            stack.append(k)
                            seen.add(k)

        return cnt

if __name__ == "__main__":
    n = 5
    edges = [[0,1],[1,2],[3,4]]
    sol = Solution()
    print(sol.countComponents(n, edges))
