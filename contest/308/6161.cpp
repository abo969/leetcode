/**
 * 6161. 从字符串中移除星号
 * 给你一个包含若干星号 * 的字符串 s 。
 * 在一步操作中，你可以：
 * 选中 s 中的一个星号。
 * 移除星号 左侧 最近的那个 非星号 字符，并移除该星号自身。
 * 返回移除 所有 星号之后的字符串。
 * 
 * https://leetcode.cn/problems/removing-stars-from-a-string/
 */

class Solution {
public:
    string removeStars(string s) {
        string res;
        for (auto& c : s) {
            if (c == '*') res.pop_back();
            else res += c;
        }

        return res;
    }
};