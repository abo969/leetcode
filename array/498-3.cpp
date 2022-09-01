/**
 * 498. 对角线遍历
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，
 * 用一个数组返回这个矩阵中的所有元素。
 * 
 * https://leetcode.cn/problems/diagonal-traverse/
 * 
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> v(m+n-1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)     // 后访问到的直接append
                v[i+j].push_back(mat[i][j]);
        }

        vector<int> res;
        for (int i = 0; i < v.size(); i++) {
            if (i % 2) {                    // 走对角线：右上
                for (int j = 0; j < v[i].size(); j++)
                    res.push_back(v[i][j]);
            } else {
                for (int j = v[i].size() - 1; j >= 0; j--)
                    res.push_back(v[i][j]);
            }
        }
        
        return res;
    }
};