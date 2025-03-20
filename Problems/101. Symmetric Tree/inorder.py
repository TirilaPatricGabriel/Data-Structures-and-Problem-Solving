# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, node: Optional[TreeNode], dir: string) -> bool:
        if node == None:
            return

        if node.left:
            self.inorder(node.left, "l")

        self.tree.append((node.val, dir))

        if node.right:
            self.inorder(node.right, "r")

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        self.tree = []
        self.inorder(root, "")

        if len(self.tree) == 1:
            return True

        if len(self.tree) % 2 == 0:
            return False

        l = r = len(self.tree) // 2

        l-=1
        r+=1
        
        while l >= 0:
            print(l, r)
            print(self.tree[l], self.tree[r])
            if self.tree[l][0] != self.tree[r][0] or self.tree[l][1] == self.tree[r][1]:
                return False
            l-=1
            r+=1
        
        return True