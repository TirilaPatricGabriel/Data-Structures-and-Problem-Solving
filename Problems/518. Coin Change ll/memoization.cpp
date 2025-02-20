#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(int amount, vector<int>& coins, int index, vector<vector<int>>& memo) {
        if (amount == 0) return 1;
        if (amount < 0 || index < 0) return 0;

        if (memo[amount][index] != -1) return memo[amount][index];

        int include = solve(amount - coins[index], coins, index, memo);
        int exclude = solve(amount, coins, index - 1, memo);

        return memo[amount][index] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(amount + 1, vector<int>(n, -1));
        return solve(amount, coins, n - 1, memo);
    }
};


int main () {

    return 0;
}