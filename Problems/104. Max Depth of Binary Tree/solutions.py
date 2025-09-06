# class Solution:
#     def findMaxDepth(self, node, h):
#         if not node:
#             return h

#         return max(self.findMaxDepth(node.left, h+1), self.findMaxDepth(node.right, h+1))


#     def maxDepth(self, root: Optional[TreeNode]) -> int:
#         return self.findMaxDepth(root, 0)