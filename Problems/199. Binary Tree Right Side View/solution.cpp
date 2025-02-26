#include <iostream>
#include <queue>
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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.emplace(root);
        int height = 0, dimLastLevel = 1, dimThisLevel = 0;
        vector<pair<int ,int>> res = {};

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(make_pair(node->val, height));
            dimLastLevel--;

            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (left != nullptr) {
                q.emplace(left);
                dimThisLevel += 1;
            }
            if (right != nullptr) {
                q.emplace(right);
                dimThisLevel += 1;
            }

            if (dimLastLevel == 0) {
                dimLastLevel = dimThisLevel;
                dimThisLevel = 0;
                height += 1;
            }
        }

        vector<int> res2 = {};

        pair<int, int> last_elem = res[0];
        for(int i=1; i<res.size(); i++) {
            if (res[i].second > last_elem.second) {
                res2.push_back(last_elem.first);
            }
            last_elem = res[i];
        }
        res2.push_back(res[res.size()-1].first);

        return res2;
    }
};

int main () {

    return 0;
}