/**
 * 11. 盛最多水的容器
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 
 * (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 * 说明：你不能倾斜容器。
 * https://leetcode.cn/problems/container-with-most-water/
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) return 0;

        int n = height.size();
        int ans = 0;

        // 双指针
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int cur = (j - i) * min(height[i], height[j]);
            ans = max(ans, cur);

            if (height[i] < height[j])  // 左边的小于右边的
                i++;                    // 左边指针向右走
            else j--;                   // 否则，右指针向左走
        }

        return ans;
    }
};