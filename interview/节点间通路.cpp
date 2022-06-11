/**
 * 面试题 04.01. 节点间通路
 * 节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。
 * https://leetcode.cn/problems/route-between-nodes-lcci/
 */

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        // 构建邻接表 adject table
        vector<vector<int>> vt(n);
        for (int i = 0; i < graph.size(); i++) {
            vt[graph[i][0]].push_back(graph[i][1]);
        }

        vector<bool> visit(n, false);
        queue<int> q;
        q.push(start);
        visit[start] = true;

        // bfs遍历图
        while (!q.empty()) {
            int u = q.front(); q.pop();
            // 遍历u可以到达的点
            for (int i = 0; i < vt[u].size(); i++) {
                int v =  vt[u][i];      // 处理u的第i个邻接点
                if (!visit[v]) {        // 如果u的第i个邻接点没有访问过
                    if (v == target)    // 如果是目标节点，返回
                        return true;

                    visit[v] = true;
                    q.push(v);
                }
            }
        }

        return false;
    }
};

