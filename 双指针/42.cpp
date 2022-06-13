/**
 * 42. 接雨水
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
 * https://leetcode.cn/problems/trapping-rain-water/
 */

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int n = height.size();
        // 双指针
        int l = 0, r = n - 1;
        int lmax = height[l], rmax = height[r];

        int res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                lmax = max(lmax, height[l]);    // 左边最大值
                res += lmax - height[l];        // 若当前比lmax小，则可以盛水
                l++;                            // 左边指针向右走
            } else {
                rmax = max(rmax, height[r]);    // 右边最大值
                res += rmax - height[r];        // 向左走，若当前比rmax小，则可以盛水
                r--;                            // 右边指针向左走
            }
        }

        return res;
    }
};