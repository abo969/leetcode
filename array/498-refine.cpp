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

        vector<int> res;
        int i = 0, j = 0;       // 从左上角开始遍历，先向右上方向走

        while (true) {
            res.emplace_back(mat[i][j]);
            if (i == m-1 && j == n-1) break;

            if ((i + j) % 2 == 0) {         // 走对角线：右上
                if (j == n-1)               // 走到最后一列
                    i++;                    // 向下走
                else if (i == 0)            // 走到第一行
                    j++;                    // 右右走
                else                        // 否则，右上走
                    i--, j++;

            } else {                        // 走对角线：左下
                if (i == m-1)               // 走到最后一行
                    j++;                    // 向右走
                else if (j == 0)            // 已走到第一列
                    i++;                    // 向下走
                else                        // 否则，左下走
                    i++, j--;
            }
        }

        return res;
    }
};