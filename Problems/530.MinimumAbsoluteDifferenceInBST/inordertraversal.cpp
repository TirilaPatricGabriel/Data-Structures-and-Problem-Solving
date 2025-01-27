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
    int minDiff;
    vector<int> values;
public:
    int  inOrderTraversal(TreeNode* node) {
        if (node->left != nullptr) {
            inOrderTraversal(node->left);
        }

        this->values.push_back(node->val);


        if (node->right != nullptr) {
            inOrderTraversal(node->right);
        }
        return node->val;
    }
    int getMinimumDifference(TreeNode* root) {
        this->minDiff = INT_MAX;
        this->inOrderTraversal(root);
        for (int i=0; i<this->values.size()-1; i++) {
            if (minDiff > this->values[i+1] - this->values[i]) minDiff = this->values[i+1] - this->values[i];
        }
        return minDiff;
    }
};

int main () {

}