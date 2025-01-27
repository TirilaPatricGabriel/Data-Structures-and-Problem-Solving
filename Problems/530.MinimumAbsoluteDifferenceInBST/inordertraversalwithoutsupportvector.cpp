#include <iostream>
#include <vector>

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
    int minDiff, prev;
public:
    Solution() : prev(-1), minDiff(INT_MAX) {}

    void inOrderTraversal(TreeNode* node) {
        if (node->left != nullptr) {
            inOrderTraversal(node->left);
        }

        if (prev != -1) {
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;

        if (node->right != nullptr) {
            inOrderTraversal(node->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        this->inOrderTraversal(root);

        return minDiff;
    }
};
int main () {

}