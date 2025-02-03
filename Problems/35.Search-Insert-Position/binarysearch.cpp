#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch (vector<int>& arr, int l, int r, int target) {
        if (l == r) {
            if (target > arr[r]) return r+1;
            return l;
        }  

        int mid = (l+r)/2;
        int elem = arr[mid];

        if (target == elem) return mid;
        else if (target > elem) return binarySearch(arr, mid+1, r, target);
        
        return binarySearch(arr, l, mid, target);
    }

    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        return binarySearch(nums, l, r, target);
    }
};

int main () {
    
    return 0;
}