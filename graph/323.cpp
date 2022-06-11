/**
 * 323. 无向图中连通分量的数目
 * 你有一个包含 n 个节点的图。给定一个整数 n 和一个数组 edges ，其中 edges[i] = [ai, bi] 表示图中 ai 和 bi 之间有一条边。
 * 返回 图中已连接分量的数目 。
 * https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/
 */

class Solution {
public:
    void dfs(vector<vector<int>>& vt, vector<bool>& vst, int u) {
        if (vst[u]) return;

        vst[u] = true;                  // 标记已访问
        for (int i = 0; i < vt[u].size(); i++) { // 处理每个邻接点
            int v = vt[u][i];
            if (!vst[v])
                dfs(vt, vst, v);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();           // m条边

        vector<vector<int>> vt(n);      // 邻接表
        for (int i = 0; i < m; i++) {   // 构建邻接表
            int u = edges[i][0];
            int v = edges[i][1];
            vt[u].emplace_back(v);      // 无向图要相互建邻接表
            vt[v].emplace_back(u);
        }

        vector<bool> vst(n, false);     // 已访问数组
        int cnt = 0;

        for (int u = 0; u < n; u++) {   // 遍历每个节点
            if (!vst[u]) {
                dfs(vt, vst, u);
                cnt++;
            }
        }

        return cnt;
    }
};