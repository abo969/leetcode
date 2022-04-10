/*
  组合
  给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
  你可以按 任何顺序 返回答案。
 */
class Solution {
public:
    vector<vector<int>> res;

    void combine(int n, int k, int start, vector<int>& cur) {
        if (cur.size() == k) {          // 递归结束，将当前组合放进结果集
            res.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++) {
            cur.push_back(i);           // 选择
            combine(n, k, i+1, cur);    // 回溯
            cur.pop_back();             // 恢复
        }
    }

    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) return res;

        vector<int> cur;
        combine(n, k, 1, cur); 
        return res;
    }
};