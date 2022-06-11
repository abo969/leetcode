/**
 * 54. 螺旋矩阵
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * https://leetcode.cn/problems/spiral-matrix/
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = n - 1;
        int top = 0, bottom = m -1;
        vector<int> res;

        int i = 0, j = 0;       // 从左上角开始
        while (top <= bottom && left <= right) {
            for (i = top, j = left; j <= right; j++)    // 向右
                res.emplace_back(matrix[i][j]);
            top++;
            if (top > bottom) break;

            for (i = top, j = right; i <= bottom; i++)  // 向下
                res.emplace_back(matrix[i][j]);
            right--;
            if (left > right) break;

            for (i = bottom, j = right; j >= left; j--)    // 向左
                res.emplace_back(matrix[i][j]);
            bottom--;

            for (i = bottom, j = left; i >= top; i--)    // 向上
                res.emplace_back(matrix[i][j]);
            left++;
        }

        return res;
    }
};