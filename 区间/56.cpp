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

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end)             // 合并当前区间
                end = max(end, intervals[i][1]);    // 修改区间end
            else {
                res.push_back({start, end});        // 保存结果
                start = intervals[i][0];            // 新的区间
                end = intervals[i][1];
            }
        }

        res.push_back({start, end});
        return res;
    }
};