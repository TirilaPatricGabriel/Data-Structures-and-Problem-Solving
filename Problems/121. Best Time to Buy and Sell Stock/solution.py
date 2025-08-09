class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 1:
            return 0

        minn = prices[0]
        max_profit = 0

        for i in range(1, len(prices)):
            minn = min(minn, prices[i])

            cur_profit = prices[i] - minn

            max_profit = max(cur_profit, max_profit)

        return max_profit

