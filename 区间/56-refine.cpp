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

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // 如果结果集为空，或者res最后一个区间end小于当前区间
            if (res.empty() || res.back()[1] < start) {
                res.push_back({start, end});    // 保存当前区间
            } else {    // 不为空，或者res最后一个区间end大于等于当前区间start
                // 修改res最后一个区间end
                res.back()[1] = max(res.back()[1], end);
            }
        }

        return res;
    }
}