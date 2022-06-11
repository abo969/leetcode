/**
 * 200. 岛屿数量
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 * https://leetcode.cn/problems/number-of-islands/
 */

class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    // 遍历一个独立的岛屿，同一个岛屿会在一个dfs里全部遍历完
    void dfs(vector<vector<char>>& g, vector<vector<bool>>& vst, int x, int y) {
        if (g[x][y] == '0' || vst[x][y]) return;

        int m = g.size();
        int n = g[0].size();
        vst[x][y] = true;               // 标记已访问
        for (int i = 0; i < 4; i++) {   // 遍历4个方向
            int u = x + dx[i];
            int v = y + dy[i];
            if (   u >= 0 && u < m
                && v >= 0 && v < n
                && g[u][v] == '1'
                && !vst[u][v])          // 范围没有越界、是岛屿、且未访问
                dfs(g, vst, u, v);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 已访问数组，初始化位false
        vector<vector<bool>> vst(m, vector<bool>(n, false));

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 是岛屿、且未访问过，寻找同一个岛屿
                if (grid[i][j] == '1' && !vst[i][j]) {
                    dfs(grid, vst, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};