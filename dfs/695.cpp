/**
 * 695. 岛屿的最大面积
 * 给你一个大小为 m x n 的二进制矩阵 grid 。
 * 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 
 * 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
 * 岛屿的面积是岛上值为 1 的单元格的数目。
 * 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
 * https://leetcode.cn/problems/max-area-of-island/
 */

class Solution {
public:
    // 左、右、上、下 4个点
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    // DFS求岛屿面积
    int dfs(vector<vector<int>>& g, int m, int n, int x, int y) {
        // 不是岛屿或者已访问过，直接返回
        if (g[x][y] == 0) return 0;

        g[x][y] = 0;    // 是岛屿且已访问过，设为0
        int curArea = 1;
        for (int i = 0; i < 4; i++) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (   u >= 0 && u < m
                && v >= 0 && v < n
                && g[u][v] == 1)        // 范围没有越界，且是岛屿
                curArea += dfs(g, m, n, u, v);
        }

        return curArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {  // 是岛屿，则去求面积
                    int curArea = dfs(grid, m, n, i, j);
                    maxArea = max(maxArea, curArea);
                }
            }
        }

        return maxArea;
    }
};