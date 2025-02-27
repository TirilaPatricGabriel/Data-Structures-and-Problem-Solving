#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(int pos, vector<int>& nums, vector<int>& robbed) {
        if (pos > nums.size()-1) return 0;
        if (pos == nums.size()-1) return nums[pos];

        if (robbed[pos] == -1) {
            robbed[pos] = max(dp(pos+2, nums, robbed) + nums[pos], dp(pos+1, nums, robbed));
        }

        return robbed[pos];
    }

    int rob(vector<int>& nums) {
        vector<int> robbed(nums.size(), -1);
        return dp(0, nums, robbed);
    }
};

int main () {
    return 0;
}