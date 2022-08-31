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

        map<int, vector<int>> hash;     // i+j => 对角线上的数据
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < nums[i].size(); j++)    // 后计算的在对角线的前面输出
                hash[i+j].insert(hash[i+j].begin(), nums[i][j]);
        }

        vector<int> res;
        for (int i = 0; i < hash.size(); i++) {
            for (auto& val : hash[i])
                res.push_back(val);
        }
        return res;
    }
};