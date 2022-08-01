/**
 * 4. 寻找两个正序数组的中位数
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 链接：https://leetcode.cn/problems/median-of-two-sorted-arrays
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 假设nums1长度小于nums2长度
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int l = 0, r = m;
        int total = m + n;

        // 分割线左边的所有元素个数为(m + n + 1)/2
        int totalLeft = (m + n + 1) / 2;

        // 在nums1数组[0, m]区间内进行适当分割
        // 使nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]
        while (l < r) {
            int i = l + (r - l + 1) / 2;    // nums1分割线左边元素个数
            int j = totalLeft - i;          // nums2分割线左边元素个数

            if (nums1[i - 1] > nums2[j])    // nums1左边最大值比nums2右边最小值大，说明分割线需要向左移
                r = i - 1;      // 下一轮搜索区间[i+1, right]
            else
                l = i;          // 下一轮搜索区间[left, i]
        }

        int i = l;
        int j = totalLeft - i;

        int leftMax1 = i == 0 ? INT_MIN : nums1[i-1];
        int rightMin1 = i == m ? INT_MAX : nums1[i];
        int leftMax2 = j == 0 ? INT_MIN : nums2[j-1];
        int rightMin2 = j == n ? INT_MAX : nums2[j];

        if (total % 2 == 1)
            return max(leftMax1, leftMax2);
        else
            return (double)(max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2;
    }
};