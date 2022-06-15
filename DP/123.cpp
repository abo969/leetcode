/**
 * 123. 买卖股票的最佳时机 III
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int bu1 = -prices[0], bu2 = -prices[0];
        int se1 = 0, se2 = 0;
        for (int i = 1; i < prices.size(); i++) {
            // bu1: 第i天买入一支股票后的利润
            bu1 = max(bu1, -prices[i]);

            // se1: 第i天卖出，完成1次交易
            se1 = max(se1, bu1 + prices[i]);

            // bu2: 第i天卖出后又买入
            bu2 = max(bu2, se1 - prices[i]);

            // se2: 第i天完成两次交易
            se2 = max(se2, bu2 + prices[i]);
        }

        return se2;
    }
};