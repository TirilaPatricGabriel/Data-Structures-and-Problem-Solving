#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;

        while (left < right) {
            mid = (left + right) / 2;

            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) {
                left = mid+1;
            } else {
                right = mid-1;
            }

        }
        if (nums[left] == target) return left;

        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1 && nums[0] == target) return 0;
        return binarySearch(nums, target);
    }
};

int main () {
    return 0;
}