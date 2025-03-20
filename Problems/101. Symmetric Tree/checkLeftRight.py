# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkSymmetry(self, leftNode, rightNode):
        if leftNode == None and rightNode == None:
            return True

        if leftNode == None or rightNode == None:
            return False

        return (leftNode.val == rightNode.val and self.checkSymmetry(leftNode.left, rightNode.right) and self.checkSymmetry(leftNode.right, rightNode.left))


    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.checkSymmetry(root, root)