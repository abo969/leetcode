/*
  全排列
  给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 */
class Solution {
public:
    void dfs(vector<int>& v, int n, int k,
        vector<int>& cur,                   // cur: 当前排列
        vector<bool>& used,                 // used: 各个数是否已使用
        set<vector<int>>& res)              // res: 结果集合，去重复
    {
        if (k == n) {                       // 已经排列了所有的数
            res.insert(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;          // 已经用过该数

            cur.push_back(v[i]);            // 选择
            used[i] = true;                 // 第i个数已使用
            dfs(v, n, k+1, cur, used, res); // 递归下一个排列
            used[i] = false;                // 恢复
            cur.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;

        int n = nums.size();
        set<vector<int>> st;
        vector<int> cur;
        vector<bool> used(n, false);
        dfs(nums, n, 0, cur, used, st);
        for (auto v: st)
            res.push_back(v);
        return res;
    }
};