"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node

        q = deque()
        q.append(node)

        clones = {}
        clones[node.val] = Node(node.val, [])

        while q:
            curnode = q.popleft()
            print(curnode.val)
            clone = clones[curnode.val]

            for n in curnode.neighbors:
                if n.val not in clones.keys():
                    clones[n.val] = Node(n.val, [])
                    q.append(n)
                    
                if n.val not in clone.neighbors:
                    clone.neighbors.append(clones[n.val])


        return clones[node.val]

