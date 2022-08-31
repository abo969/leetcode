/**
 * @file 1424.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        int maxn = nums[0].size();
        for (int i = 1; i < m; i++)
            maxn = max(maxn, nums[i].size());

        vector<int> res;
        for (int r = 0; r < m; r++) {   // 第一列每个点作为起始点向右上走
            int i = r, j = 0;           // 起始点：(r, 0)
            while (i >= 0) {            // 直到走到第一行
                if (j < nums[i].size()) // 判断当前第i行范围
                    res.emplace_back(nums[i][j]);
                i--, j++;               // 向右上走
            }
        }

        int start = 1;
        int r = m - 1;                  // 最后一行的每个点作为起始点继续右上走，直到走到最后一列
        while (r >= 0) {
            for (int c = start; c < nums[r].size(); c++) {
                int i = r, j = c;           // 起始点：(m-1, c)
                while (i >= 0) {
                    if (j < nums[i].size())
                        res.emplace_back(nums[i][j]);
                    if (j > maxn) break;
                    i--, j++;
                }
            }

            start = max(start+1, nums[r].size()+1);     // 下一轮从上一轮最后一个元素右上的下一个位置开始
            r--;
        }

        return res;
    }
};