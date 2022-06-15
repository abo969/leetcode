/**
 * 688. 骑士在棋盘上的概率
 * 在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column) 开始，
 * 并尝试进行 k 次移动。行和列是 从 0 开始 的，所以左上单元格是 (0,0) ，
 * 右下单元格是 (n - 1, n - 1) 。
 * 象棋骑士有8种可能的走法，如下图所示。
 * 每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。
 * 
 * https://leetcode.cn/problems/knight-probability-in-chessboard/
 */

class Solution {
public:
    // 8个方向x、y的变化
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

    double knightProbability(int n, int k, int row, int column) {
        // f[step][i][j]：走了step步到达点(i, j)的概率
        vector<vector<vector<double>>> f(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));

        for (int step = 0; step <=k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (step == 0)
                        f[step][i][j] = 1;
                    else {
                        double s = 0;
                        for (int u = 0; u < 8; u++) {
                            int x = i + dx[u];
                            int y = j + dy[u];
                            // 再走一步到达点(x, y)，仍留在棋盘上
                            if (x >= 0 && x < n && y >= 0 && y < n)
                                s += f[step-1][x][y];
                        }
                        f[step][i][j] = s / 8;
                    }
                }
            }
        }

        return f[k][row][column];

    }
};