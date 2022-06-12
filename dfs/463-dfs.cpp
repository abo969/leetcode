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
    int dfs(vector<vector<int>>& g, int m, int n, int x, int y) {
        // 是陆地，或者是边界，计算1个周长
        if (x < 0 || x >= m 
            || y < 0 || y >= n
            || g[x][y] == 0) return 1;

        // 不是岛屿或者已访问过(已访问过会被比较为-1)，不计算周长
        if (g[x][y] == -1) return 0;

        g[x][y] = -1;    // 标记已访问过
        int curLen = 0;
        for (int i = 0; i < 4; i++) {
            int u = x + dx[i];
            int v = y + dy[i];
            // (u, v)这个点是陆地，继续计算
            curLen += dfs(g, m, n, u, v);
        }
        return curLen;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {   // 是陆地，则计算周长
                    total += dfs(grid, m, n, i, j);
                }
            }
        }

        return total;
    }
};