/**
 * 6162. 收集垃圾的最少总时间
 * 给你一个下标从 0 开始的字符串数组 garbage ，其中 garbage[i] 表示第 i 个房子的垃圾集合。
 * garbage[i] 只包含字符 'M' ，'P' 和 'G' ，但可能包含多个相同字符，每个字符分别表示一单位
 * 的金属、纸和玻璃。垃圾车收拾 一 单位的任何一种垃圾都需要花费 1 分钟。
 * 同时给你一个下标从 0 开始的整数数组 travel ，其中 travel[i] 是垃圾车从房子 i 行驶到房子
 * i + 1 需要的分钟数。
 * 城市里总共有三辆垃圾车，分别收拾三种垃圾。每辆垃圾车都从房子 0 出发，按顺序 到达每一栋房子。
 * 但它们 不是必须 到达所有的房子。
 * 任何时刻只有 一辆 垃圾车处在使用状态。当一辆垃圾车在行驶或者收拾垃圾的时候，另外两辆车不能
 * 做任何事情。
 * 请你返回收拾完所有垃圾需要花费的 最少 总分钟数。
 * 
 * https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/
 * 
 */

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int res = garbage[0].size();
        string op = "MPG";

        // 分别对每种垃圾进行处理
        for (auto c : op) {
            int pos = 0;

            for (int i = 1; i < n; i++) {   // 处理每个房子
                int cnt = 0;    // 当前垃圾c的个数
                for (auto& g : garbage[i]) {
                    if (g == c) cnt++;
                }

                res += cnt;                 // 收拾当前垃圾需要的时间
                if (cnt > 0)                // 该房子有当前垃圾c
                    pos = i;                // 垃圾车需要走到该房子
            }

            // 处理所有房子后，pos记录处理当前垃圾c的垃圾车需要最远走到哪个房子
            for (int i = 0; i < pos; i++)
                res += travel[i];         // 计算行驶需要的时间
        }

        return res;
    }
};