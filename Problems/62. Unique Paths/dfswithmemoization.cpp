#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dfs (int i, int j, int m, int n, vector<vector<int>>& memo) {
        if (i > m || j > n) return 0;
        if (i == m && j == n) {
            return 1;
        }

        if (memo[i][j] != -1) return memo[i][j];

        return memo[i][j] = dfs(i + 1, j, m, n, memo) + dfs(i, j+1, m, n, memo);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(0, 0, m-1, n-1, memo);
    }
};

int main () {

    return 0;
}