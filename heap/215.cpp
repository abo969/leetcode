/**
 * 215. 数组中的第K个最大元素
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // 小顶堆：top最小
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; i++) q.push(nums[i]);

        for (int i = k; i < n; i++) {
            if (nums[i] > q.top()) {    // 比top大，入堆
                q.pop();                // 把最小的删除
                q.push(nums[i]);        // 将当前元素入堆
            }
        }

        return q.top();
    }
};