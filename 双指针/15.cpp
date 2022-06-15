/**
 * 15. 三数之和
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。 
 * https://leetcode.cn/problems/3sum/
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        sort(nums.begin(), nums.end()); // 从小到大排序
        vector<vector<int>> res;

        int n = nums.size();
        for (int k = 0; k < n; k++) {
            if (nums[k] > 0)            // 已从小到大排序，后面不会再有和为0的序列
                return res;

            if (k > 0 && nums[k] == nums[k-1]) // k指向的数去重复
                continue;
                
            int i = k + 1;              // 双指针,i 从k下一个开始向右移动
            int j = n - 1;              // j从最后一个开始向左移动
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum == 0) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    // i,j指向的数去重复
                    while (i < j && nums[i] == nums[i+1]) i++;
                    while (i < j && nums[j] == nums[j-1]) j--;

                    // 双指针分别向右、向左移动
                    i++, j--;
                } 
                else if (sum > 0) j--;
                else if (sum < 0) i++;
            }
        }

        return res;
    }
};