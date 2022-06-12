/**
 * 253. 会议室 II
 * 给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间
 * intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。
 * https://leetcode.cn/problems/meeting-rooms-ii/
 */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 类似修正带
        vector<vector<int>> tag;
        for (int i = 0; i < intervals.size(); i++) {
            tag.push_back({intervals[i][0], 1});  // 涂上一层，+1
            tag.push_back({intervals[i][1], -1}); // 擦掉一层，-1
        }

        // 按时间排序
        sort(tag.begin(), tag.end());

        int cnt = 0;        // 当前需要会议室的数量
        int maxtag = 0;     // 涂修正带最大层数就是所需会议室个数
        for (int i = 0; i < tag.size(); i++) {
            cnt += tag[i][1];
            maxtag = max(maxtag, cnt);
        }

        return maxtag;
    }
};