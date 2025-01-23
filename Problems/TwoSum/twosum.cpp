#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int i;
        vector<int> res = {};
        for (i = 0; i < nums.size() - 1; i++) {
            int newTarget = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == newTarget) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

class FasterSolutionUsingMap {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map = {};

        for (int i=0; i<nums.size(); i++) {
            int newTarget = target - nums[i];
            if (map.find(newTarget) != map.end()) {
                vector<int> res = {map[newTarget], i};
                return res;
            }
            map[nums[i]] = i;
        }
        return {};
    }
};