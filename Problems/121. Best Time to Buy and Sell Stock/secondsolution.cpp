#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, res = INT_MIN;
        for (int i=0; i<prices.size(); i++) {
            if (res < prices[i] - minVal) res = prices[i] - minVal;
            if (minVal > prices[i]) minVal = prices[i];
        }

        return max(0, res);
    }
};

int main () {

    return 0;
}