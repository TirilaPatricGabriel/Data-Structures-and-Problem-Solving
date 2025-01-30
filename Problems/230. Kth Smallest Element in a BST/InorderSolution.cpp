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
    vector<int> nodes;
    int k;
    int result;
public:
    void inorder (TreeNode* node) {
        if (k == 0) return;
        if (node->left != nullptr) {
            inorder(node->left);
        }

        k-=1;
        if (k == 0) this->result = node->val;

        if (node->right != nullptr) {
            inorder(node->right);
        }

    }
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);
        return this->result;
    }
};

int main () {
    return 0;
}