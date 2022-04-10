/*
  全排列
  给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 */
class Solution {
public:
    void dfs(int len, int cnt, vector<int>& cur, vector<vector<int>>& res) {
        // 当前已经排了所有的数
        if (cnt == len) {
            res.push_back(cur);
            return;
        }

        for (int i = cnt; i < len; i++) {
            // 动态数组
            swap(cur[i], cur[cnt]);

            // 下一个层继续深度搜索
            dfs(len, cnt+1, cur, res);

            // 回溯
            swap(cur[i], cur[cnt]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {        
        vector<vector<int>> res;
        if (nums.size() == 0) return res;

        dfs(nums.size(), 0, nums, res);
        return res;
    }
};