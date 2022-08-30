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
        int dir = 1;            // 方向：0: 左下、1: 右上

        while (true) {
            res.emplace_back(mat[i][j]);
            if (i == m-1 && j == n-1) break;

            if (dir == 1) {                     // 走对角线：右上
                if (i == 0 && j == n-1)         // 走到右上角
                    i = 1, dir = 0;             // 向下走
                else if (i == 0)                // 走到第一行
                    j++, dir = 0;               // 右右走
                else if (j == n-1)              // 走到最后一列
                    i++, dir = 0;               // 向下走
                else                            // 否则，右上走
                    i--, j++;

            } else if (dir == 0) {              // 走对角线：左下
                if (i == m-1 && j == 0)         // 走到左下角
                    j = 1, dir = 1;             // 向右走
                else if (j == 0)                // 已走到第一列
                    i++, dir = 1;               // 向下走
                else if (i == m-1)              // 走到最后一行
                    j++, dir = 1;               // 向右走
                else                            // 否则，左下走
                    i++, j--;
            }
        }

        return res;
    }
};