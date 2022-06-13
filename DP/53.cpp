/**
 * 53. 最大子数组和
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组
 * （子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。 
 * https://leetcode.cn/problems/maximum-subarray/
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> f(n, 0);

        f[0] = nums[0];
        int maxs = f[0];
        // 动态规划
        // f[i]：前i个元素最大的连续子数组和
        // f[i] 取决于nums[i]、f[i-1] + nums[i]的大小
        for (int i = 1; i < n; i++) {
            f[i] = max(nums[i], f[i-1] + nums[i]);
            maxs = max(maxs, f[i]);
        }

        return maxs;
    }
}