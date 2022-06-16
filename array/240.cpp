/**
 * 240. 搜索二维矩阵 II
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。 
 * https://leetcode.cn/problems/search-a-2d-matrix-ii/
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;       // 从右上角开始
        while (i < m && j >= 0) {
            if (target == matrix[i][j]) return true;
            
            if (target > matrix[i][j]) i++;
            else j--;
        }

        return false;
    }
};