#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end = nums.size()-1, i=0, k=0;

        while(i<=end) {
            if (nums[i] == val) {
                swap(nums[i], nums[end]);
                if (nums[i] == val) i--;
                end--;
                k++;
            }
            i++;
        }

        return nums.size() - k;
    }
};

int main () {
    return 0;
}