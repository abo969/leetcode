/**
 * 6160. 和有限的最长子序列
 * 给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。
 * 返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于
 * queries[i] 的 子序列 的 最大 长度  。
 * 子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。
 * 
 * https://leetcode.cn/problems/longest-subsequence-with-limited-sum/
 */

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        // 计算前缀和
        vector<int> f(nums.size(), 0);
        f[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            f[i] = f[i-1] + nums[i];
        
        vector<int> res;
        for (auto q : queries) {
            int k = 0;      // 元素个数，从0开始累加
            while (k < nums.size() && f[k] <= q) k++;

            res.push_back(k);
        }

        return res;
    }
};