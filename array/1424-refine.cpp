/**
 * 1424. 对角线遍历 II
 * 给你一个列表 nums ，里面每一个元素都是一个整数列表。
 * 请你依照下面各图的规则，按顺序返回 nums 中对角线上的整数。
 *
 * https://leetcode.cn/problems/diagonal-traverse-ii/
 * 
 */

class Solution {
public:
    struct Node {
        int i, j;
        int val;

        Node(int _i, int _j, int _val): i(_i), j(_j), val(_val) {}

        // 下标之和小的先输出，下标之和相同的按列从前向后排序
        bool operator<(const Node& node) {
            if (i + j != node.i + node.j)
                return i + j < node.i + node.j;
            return j < node.j;
        }
    };

    // 排序思想
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();

        vector<Node> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < nums[i].size(); j++)
                v.push_back(Node(i, j, nums[i][j]));
        }

        sort(v.begin(), v.end());

        vector<int> res;
        for (auto& node : v)
            res.push_back(node.val);
        return res;
    }
};