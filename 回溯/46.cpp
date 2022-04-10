/*
  全排列
  给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 */
class Solution {
public:
    vector<vector<int>> res;

    void permute(vector<int>& v, int n, int k, vector<int>& cur, vector<bool>& used) {
        if (k == n) {                       // 已经排列了所有的数
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;          // 已经用过该数

            cur.push_back(v[i]);            // 选择
            used[i] = true;                 // 第i个数已使用
            permute(v, n, k+1, cur, used);  // 递归下一个排列
            used[i] = false;                // 恢复
            cur.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return res;

        int n = nums.size();
        vector<int> cur;
        vector<bool> used(n, false);
        permute(nums, n, 0, cur, used);
        return res;
    }
};