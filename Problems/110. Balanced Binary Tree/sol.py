# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def solve(node: Optional[TreeNode]) -> bool:
            if not node:
                return 0

            left_size = solve(node.left)
            if left_size == -1:
                return -1

            right_size = solve(node.right)
            if right_size == -1:
                return -1

            if abs(right_size - left_size) > 1:
                return -1

            return 1 + max(left_size, right_size)

        res = solve(root)

        return res != -1