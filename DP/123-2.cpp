/**
 * 123. 买卖股票的最佳时机 III
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int k = 2;
        vector<int> buy(3, -prices[0]);
        vector<int> sell(3, 0);

        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        return sell[k];
    }
};