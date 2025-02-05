#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int res;
public:
    Solution() : res(INT_MIN) {}

    int dp(vector<int>& prices, int i) {
        if (i == prices.size() - 1) return prices[i];
        int Max = max(prices[i+1], dp(prices, i+1));

        if (Max - prices[i] > res) res = max(0, Max - prices[i]);

        return Max;
    }

    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) return 0;
        dp(prices, 0);

        return res;
    }
};

int main () {

    return 0;
}