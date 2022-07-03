/**
 * 240. 搜索二维矩阵 II
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。 
 * https://leetcode.cn/problems/search-a-2d-matrix-ii/
 */

class Solution {
public:
    // 缩小搜索范围(x1, y1) ~ (x2, y2)之间的区域
    // 范围不超过maxx, maxy
    bool searchMatrix(vector<vector<int>>& v,
            int target,
            int x1, int y1, int x2, int y2,
            int maxx, int maxy)
    {
        if (x1 > maxx || y1 > maxy) return false;
        if (x1 > x2 || y1 > y2) return false;

        // 只有一个点，直接判断即可
        if (x1 == x2 && y1 == y2)
            return v[x1][y1] == target;

        // 二分
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y2) >> 1;
        if (v[midx][midy] == target) return true;

        if (v[midx][midy] < target) {
            return searchMatrix(v, target, midx+1, y1, x2, midy, maxx, maxy)    // 右上
                || searchMatrix(v, target, x1, midy+1, midx, y2, maxx, maxy)    // 左下
                || searchMatrix(v, target, midx+1, midy+1, x2, y2, maxx, maxy); // 右下
        } else {
            return searchMatrix(v, target, midx+1, y1, x2, midy, maxx, maxy)    // 右上
                || searchMatrix(v, target, x1, midy+1, midx, y2, maxx, maxy)    // 左下
                || searchMatrix(v, target, x1, y1, midx, midy, maxx, maxy);     // 左上
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        return searchMatrix(matrix, target, 0, 0, m-1, n-1, m-1, n-1);
    }
};