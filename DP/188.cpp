/**
 * 188. 买卖股票的最佳时机 IV
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> buy(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);

        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        return sell[k];
    }
};