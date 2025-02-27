#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size()+1, -1);

        memo[0] = 0;
        memo[1] = nums[0];

        for (int i=1; i<nums.size(); i++) {
            memo[i+1] = max(memo[i-1] + nums[i], memo[i]);
        }
        return memo[nums.size()];
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;

        for (int num : nums) {
            int temp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = temp;
        }

        return prev1;
    }
};