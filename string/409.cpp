/**
 * 409. 最长回文串
 * 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 * https://leetcode.cn/problems/longest-palindrome/
 */
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() < 2) return s.size();

        int n = s.size();
        // 统计每个字符出现次数
        vector<int> f(256, 0);
        for (int i = 0; i < n; i++) f[s[i]]++;

        // 统计每个字符长度：偶数直接加上、奇数长度的字符长度也去偶数
        int len = 0;
        for (int i = 0; i < f.size(); i++) {
            if (f[i] % 2 == 0) len += f[i];
            else len += f[i] - 1;
        }

        // 奇数长度的字符只能取一个作为中心点
        return (len < n) ? ++len : len;
    }
};