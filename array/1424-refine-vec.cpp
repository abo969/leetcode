/**
 * 1424. 对角线遍历 II
 * 给你一个列表 nums ，里面每一个元素都是一个整数列表。
 * 请你依照下面各图的规则，按顺序返回 nums 中对角线上的整数。
 *
 * https://leetcode.cn/problems/diagonal-traverse-ii/
 * 
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        int mx = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < nums[i].size(); j++)    // 后访问到的直接append
                mx = (i + j > mx) ? i+j : mx;

        vector<vector<int>> v(mx+1);                    // i+j => 对角线上的数据
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < nums[i].size(); j++)    // 后访问到的直接append
                v[i+j].push_back(nums[i][j]);
        }

        vector<int> res;
        for (int i = 0; i < v.size(); i++) {
            for (int j = v[i].size() - 1; j >= 0; j--)
                res.push_back(v[i][j]);                 // 倒着输出
        }
        return res;
    }
};