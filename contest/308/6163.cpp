/**
 * 6163. 给定条件下构造矩阵
 * 给你一个 正 整数 k ，同时给你：
 * 一个大小为 n 的二维整数数组 rowConditions ，其中 rowConditions[i] = [abovei, belowi] 和
 * 一个大小为 m 的二维整数数组 colConditions ，其中 colConditions[i] = [lefti, righti] 。
 * 两个数组里的整数都是 1 到 k 之间的数字。
 * 你需要构造一个 k x k 的矩阵，1 到 k 每个数字需要 恰好出现一次 。剩余的数字都是 0 。
 * 
 * 矩阵还需要满足以下条件：
 * 对于所有 0 到 n - 1 之间的下标 i ，数字 abovei 所在的 行 必须在数字 belowi 所在行的上面。
 * 对于所有 0 到 m - 1 之间的下标 i ，数字 lefti 所在的 列 必须在数字 righti 所在列的左边。
 * 返回满足上述要求的 任意 矩阵。如果不存在答案，返回一个空的矩阵。
 * 
 * https://leetcode.cn/problems/build-a-matrix-with-conditions/
 * 
 */

class Solution {
public:
    vector<int> topsort(vector<vector<int>>& vv, int n) {
        vector<vector<int>> g(n+1);
        vector<int> d(n+1);

        for (auto& v : vv) {
            int x = v[0], y = v[1];
            g[x].push_back(y);
            d[y]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (!d[i]) q.push(i);

        vector<int> res;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            res.push_back(t);
            for (int u : g[t])
                if (--d[u] == 0)
                    q.push(u);
        }

        return res;
    }

    int get(vector<int>& v, int x) {
        vector<int>::iterator it = std::find(v.begin(), v.end(), x);
        if (it != v.end()) return it - v.begin();
        return -1;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto row = topsort(rowConditions, k);
        auto col = topsort(colConditions, k);

        if (row.size() < k || col.size() < k) return {};

        vector<vector<int>> res(k, vector<int>(k));
        for (int i = 1; i <= k; i++) {
            res[get(row, i)][get(col, i)] = i;
        }

        return res;
    }
};