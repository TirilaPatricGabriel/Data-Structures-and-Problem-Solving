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
    vector<pair<int,int>> nodesLeft; // first node value, second direction from parent
    vector<pair<int, int>> nodesRight;
public:

    void inorder (TreeNode* node, bool tree, bool dir) {
        if (node->left != nullptr) {
            inorder(node->left, tree, 0);
        }

        if (tree == 0) {
            nodesLeft.push_back(make_pair(node->val, dir));
        } else nodesRight.push_back(make_pair(node->val, dir));

        if (node->right != nullptr) {
            inorder(node->right, tree, 1);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return 1;
        if (root->left == nullptr || root->right == nullptr) return 0;

        this->inorder(root->left, 0, 0);
        this->inorder(root->right, 1, 1);

        if (nodesLeft.size() != nodesRight.size()) return 0;

        for (int i=0; i<this->nodesLeft.size(); i++) {
            if (this->nodesLeft[i].first != this->nodesRight[this->nodesRight.size() - i - 1].first) return 0;
            else if (this->nodesLeft[i].second == this->nodesRight[this->nodesRight.size() - i - 1].second) return 0;
        }
        return 1;
    }
};

int main () {

    return 0;
}
