#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<vector<int>> res;
public:

    void bk (vector<int>& nums, unordered_map<int, bool> visited, vector<int>& permutation) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (visited.find(nums[i]) == visited.end() || visited[nums[i]] == false) {
                visited[nums[i]] = true;
                permutation.push_back(nums[i]);
                bk(nums, visited, permutation);
                permutation.pop_back();
                visited[nums[i]] = false;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> visited = {};
        vector<int> permutation = {};
        bk(nums, visited, permutation);
        return res;
    }
};

int main () {

    return 0;
}