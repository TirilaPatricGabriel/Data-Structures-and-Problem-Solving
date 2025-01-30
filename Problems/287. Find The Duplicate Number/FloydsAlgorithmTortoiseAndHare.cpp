#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise1 = 0, tortoise2 = 0, hare = 0;
        int i=0;
        while (tortoise1 != hare || i == 0) {
            hare = nums[nums[hare]];
            tortoise1 = nums[tortoise1];
            i = 1;
        }

        while (tortoise1 != tortoise2) {
            tortoise1 = nums[tortoise1];
            tortoise2 = nums[tortoise2];
        }

        return tortoise1;
    }
};

int main () {
    return 0;
}