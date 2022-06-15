/**
 * 122. 买卖股票的最佳时机 II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        vector<int> profit(n, 0);
        for (int i = 1; i < n; i++)
            profit[i] = prices[i] - prices[i-1];
        //0 -6 4 -2 3 -2 

        // 利润大于0才会选择交易
        int maxpro = 0;
        for (int i = 1; i < n; i++) {
            if (profit[i] > 0) maxpro += profit[i];
        }

        return maxpro;
    }
};