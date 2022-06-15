/**
 * 121. 买卖股票的最佳时机
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int res = 0;
        int lmin = INT_MAX;     // 记录历史最低点价格
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            lmin = min(lmin, prices[i]);
            res = max(res, prices[i] - lmin);
        }

        return res;
    }
};