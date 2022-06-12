/**
 * 56. 合并区间
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
 * 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * https://leetcode.cn/problems/merge-intervals/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        vector<int> pre = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            // pre区间end小于当前区间start
            if (pre[1] < intervals[i][0]) {
                res.push_back(pre);     // 保存pre区间
                pre = intervals[i];     // 更新pre
            } else {                    // 否则，更新pre区间end
                pre[1] = max(pre[1], intervals[i][1]);
            }
        }

        res.push_back(pre);
        return res;
    }
};