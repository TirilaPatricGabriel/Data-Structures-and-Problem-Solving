#include <iostream>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* traverse (TreeNode* node, TreeNode* p, TreeNode* q) {
        if (p->val == node->val || q->val == node->val) return node;

        if ((p->val < node->val && q->val > node->val) || (p->val > node->val && q->val < node->val)) {
            return node;
        }

        if (p->val < node->val && q->val < node->val) return traverse(node->left, p, q);

        return traverse(node->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root, p, q);
    }
};

int main () {

    return 0;
}