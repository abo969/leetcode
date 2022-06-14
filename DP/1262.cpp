/**
 * 1262. 可被三整除的最大和
 * 给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。
 * https://leetcode.cn/problems/greatest-sum-divisible-by-three/ 
 */

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        if (nums.empty()) return 0;

        // 动态规划考虑
        int n = nums.size();
        // f(i, 0): nums[0 ~ i] 之间的数被3整除的最大和
        // f(i, 1): nums[0 ~ i] 之间的数被3整除余1的最大和
        // f(i, 2): nums[0 ~ i] 之间的数被3整除余2的最大和
        vector<vector<int>> f(n + 1, vector<int>(3, 0));

        f[0][0] = 0;
        f[0][1] = INT_MIN;
        f[0][2] = INT_MIN;

        // 前i个数：i 为 1 ~ n, 前1个数是nums[i-1]
        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 == 0) {
                f[i+1][0] = max(f[i][0], f[i][0] + nums[i]);
                f[i+1][1] = max(f[i][1], f[i][1] + nums[i]);
                f[i+1][2] = max(f[i][2], f[i][2] + nums[i]);
            } else if (nums[i] % 3 == 1) { 
                // 前i个数整除为0，那么第i个数整除为2即可满足前i+1个整除为0
                f[i+1][0] = max(f[i][0], f[i][2] + nums[i]);

                // 前i个数整除为1，那么第i个数整除为0即可满足前i+1个整除为0
                f[i+1][1] = max(f[i][1], f[i][0] + nums[i]);

                // 前i个数整除为2，那么第i个数整除为1即可满足前i+1个整除为2
                f[i+1][2] = max(f[i][2], f[i][1] + nums[i]);
            } else if (nums[i] % 3 == 2) {
                // 前i个数整除为2，那么第i个数整除为1即可满足前i+1个整除为0
                f[i+1][0] = max(f[i][0], f[i][1] + nums[i]);

                // 前i个数整除为2，那么第i个数整除为2即可满足前i+1个整除为1
                f[i+1][1] = max(f[i][1], f[i][2] + nums[i]);

                // 前i个数整除为2，那么第i个数整除为0即可满足前i+1个整除为2
                f[i+1][2] = max(f[i][2], f[i][0] + nums[i]);
            }
        }

        return f[n][0];
    }
};