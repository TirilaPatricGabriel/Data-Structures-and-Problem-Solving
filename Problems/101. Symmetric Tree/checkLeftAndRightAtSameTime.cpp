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

    bool checkAtSameTime (TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return 1;
        if (left == nullptr || right == nullptr) return 0;

        return (left->val == right->val && checkAtSameTime(left->left, right->right) && checkAtSameTime(left->right, right->left));
    }

    bool isSymmetric(TreeNode* root) {
        return this->checkAtSameTime(root->left, root->right);
    }
};

int main () {

    return 0;
}
