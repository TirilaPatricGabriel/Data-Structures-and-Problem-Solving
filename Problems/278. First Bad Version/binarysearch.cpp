#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            if (n == 1) return 1;
            long left = 1, right = n, mid;
            int firstBad = -1;
            while (left < right) {
                mid = (left+right)/2;
                if (isBadVersion(mid)) {
                    firstBad = mid;
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
            if (left == right && (left < firstBad || firstBad == -1) && isBadVersion(left)) 
                return left;
            return firstBad;
        }
    };

int main () {

    return 0;
}