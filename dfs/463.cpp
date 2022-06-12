/**
 * 463. 岛屿的周长
 * 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， 
 * grid[i][j] = 0 表示水域。
 * 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，
 * 但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1
 * 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
 * https://leetcode.cn/problems/island-perimeter/
 */

class Solution {
public:
    // 左、右、上、下 4个点
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    // 计算g[x][y]这一块陆地与水、边界的周长
    int calc(vector<vector<int>>& g, int m, int n, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int u = x + dx[i];
            int v = y + dy[i];
            // (u, v)这个点是边界、或者是水域，需要计算到周长里
            if (u < 0 || u >= m || v < 0 || v >= n || g[u][v] == 0)
                cnt++;
        }
        return cnt;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {   // 是陆地，则计算周长
                    total += calc(grid, m, n, i, j);
                }
            }
        }

        return total;
    }
};