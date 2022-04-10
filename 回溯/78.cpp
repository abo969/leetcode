#include<iostream>
#include<vector>
using namespace std;

/*
  子集
  给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
  解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 */
class Solution {
public:
    vector<vector<int> > res;

    void subset(vector<int>& v, int start, vector<int>& cur) {
        // 记录结果
        res.push_back(cur);

        for (int i = start; i < v.size(); i++) {
            cur.push_back(v[i]);        // 选择
            subset(v, i + 1, cur);      // 递归回溯
            cur.pop_back();             // 恢复
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        if (nums.empty()) return res;

        vector<int> cur;
        subset(nums, 0, cur);
        return res;
    }
};

void output(vector<vector<int> >& res) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<int> v = {1, 2, 3};
    vector<vector<int> > res = s.subsets(v);
    output(res);
    return 0;
}