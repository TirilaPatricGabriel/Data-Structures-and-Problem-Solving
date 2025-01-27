#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int i=0, j=1;

        while (j<nums.size()){
            while (j<nums.size() && nums[i] == nums[j]) {
                j++;
            }
            if (j >= nums.size()) break;
            nums[i+1] = nums[j];
            i = i+1;
        }

        return i+1;
    }
};

int main () {

}