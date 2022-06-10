/*
647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/palindromic-substrings/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    // 统计字符串s以l、r为回文串中心的回文串的个数
    // 一般：l = r，即回文中心为一个字符，回文串长度为奇数
    //  或者 r = l + 1，即回文中心为相邻的两个字符，回文串长度为偶数
    int countSubstrings(const string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            cnt++;
            l--, r++;   // 从中心点向左右拓展
        }
        return cnt;
    }

    int countSubstrings(string s) {
        if (s.size() < 2) return 1;

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += countSubstrings(s, i, i);    // 考虑奇数长度
            ans += countSubstrings(s, i, i+1);  // 考虑偶数长度
        }

        return ans;
    }
};