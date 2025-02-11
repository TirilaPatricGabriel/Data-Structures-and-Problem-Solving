#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int climb (int stair, int n, unordered_map<int, int>& memo) {
            if (stair == n) return 1;
            if (stair > n) return 0;
    
            if (memo.find(stair) != memo.end()) return memo[stair];
            
            return memo[stair] = climb(stair+1, n, memo) + climb(stair+2, n, memo);
        }
    
        int climbStairs(int n) {
            unordered_map<int, int> memo = {};
            return climb(0, n, memo);
        }
    };

int main () {
    return 0;
}