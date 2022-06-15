/**
 * 1. 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值
 * target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 * https://leetcode.cn/problems/two-sum/
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // num -> index：数据->位置 索引
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (hash.count(diff)) return {hash[diff], i};
            hash[nums[i]] = i;
        }

        return {};
    }
};