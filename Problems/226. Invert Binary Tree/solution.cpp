#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    void invert (TreeNode* node) {
        if (node == nullptr) return;

        invert(node->left);
        invert(node->right);

        TreeNode* curr = node->left;
        node->left = node->right;
        node->right = curr;
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

int main () {
    return 0;
}