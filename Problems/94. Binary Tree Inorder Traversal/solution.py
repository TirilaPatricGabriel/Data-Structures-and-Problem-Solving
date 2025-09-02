# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.inorder_traversal = []
    
    def inorderTraversalRecursive(self, node):
        if node.left:
            self.inorderTraversalRecursive(node.left)

        self.inorder_traversal.append(node.val)

        if node.right:
            self.inorderTraversalRecursive(node.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        self.inorderTraversalRecursive(root)

        return self.inorder_traversal