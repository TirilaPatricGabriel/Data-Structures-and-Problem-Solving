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
    int minDiff;
public:
    int getMaxLeft (TreeNode *node) {
        if (node->left == nullptr) return node->val;

        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->val;
    }
    int getMinRight (TreeNode *node) {
        if (node->right == nullptr) return node->val;

        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }
    void updateMinDiff(TreeNode* node) {
        int maxLeft, minRight, dif1, dif2;
        if (node->left != nullptr) {
            maxLeft = this->getMaxLeft(node);
            dif1 = node->val - maxLeft;
            if (minDiff > dif1) minDiff = dif1;
        }
        if (node->right != nullptr) {
            minRight = this->getMinRight(node);
            dif2 = minRight - node->val;
            if (minDiff > dif2) minDiff = dif2;
        }
    }

    void traverseTheBST (TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) return;

        if (node->left != nullptr) {
            traverseTheBST(node->left);
        }
        if(node->right != nullptr) {
            traverseTheBST(node->right);
        }

        this->updateMinDiff(node);
    }

    int getMinimumDifference(TreeNode* root) {
        this->minDiff = INT_MAX;
        this->traverseTheBST(root);
        return this->minDiff;
    }
};

int main() {
    return 0;
}