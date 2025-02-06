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
    bool balanced;
public:
    Solution() : balanced(true) {}
    int checkBalance(TreeNode* node) {
        if (!this->balanced) return INT_MIN;

        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) return 1;

        if (node->left == nullptr) {
            int heightOfRight = checkBalance(node->right);
            if (heightOfRight > 1) {
                this->balanced = false;
                return INT_MIN;
            }
            return heightOfRight + 1;
        }

        if (node->right == nullptr) {
            int heightOfLeft = checkBalance(node->left);
            if (heightOfLeft > 1) {
                this->balanced = false;
                return INT_MIN;
            }
            return heightOfLeft + 1;
        }

        int heightLeft = checkBalance(node->left), heightRight = checkBalance(node->right);

        if (!this->balanced) return INT_MIN;

        int dif = abs(heightLeft - heightRight);

        if (dif > 1) {
            this->balanced = false;
            return INT_MIN;
        }

        return max(heightLeft, heightRight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        checkBalance(root);

        return this->balanced;
    }
};

int main () {

    return 0;
}