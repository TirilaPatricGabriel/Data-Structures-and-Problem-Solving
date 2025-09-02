# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversalRecursive(self, node):
        if not node:
            return []

        result = []

        result.extend(self.inorderTraversalRecursive(node.left))
        result.append(node.val)
        result.extend(self.inorderTraversalRecursive(node.right))
        
        return result

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return self.inorderTraversalRecursive(root)
