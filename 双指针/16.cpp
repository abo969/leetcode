/**
 * 16. 最接近的三数之和
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
 * 请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 返回这三个数的和。
 * 假定每组输入只存在恰好一个解。
 * https://leetcode.cn/problems/3sum-closest/
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());     // 从小到大排序
        int n = nums.size();
        int best = 1e7;

        for (int k = 0; k < n; k++) {
            int i = k + 1;      // 双指针，i从k+1开始
            int j = n - 1;      // j从最后一个元素开始
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];

                // 如果更接近，更新best
                if (abs(sum - target) < abs(best - target))
                    best = sum;

                if (sum == target) return target;
                if (sum > target) j--;
                else i++;
            }
        }

        return best;
    }
};