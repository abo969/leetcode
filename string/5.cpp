/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-palindromic-substring/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    // f(i, j)：第i到j个字符是否是回文串
    // 取决于f(i+1, j-1)是回文串、且s[i]==s[j]
    // f(i, j) = f(i+1, j-1) && s[i]==s[j]
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;

        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n));

        // 长度为1的字符串是回文串
        for (int i = 0; i < n; i++) f[i][i] = true;

        int begin = 0;
        int maxLen = 1;

        // 枚举长度，从2开始
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                int j = i + l - 1;  // 右边界
                if (j >= n) break;

                if (s[i] == s[j]) {
                    // s[i]==s[j]且长度为2或3，是回文串，如：aa, aba
                    if (l < 4) f[i][j] = true;
                    else f[i][j] = f[i+1][j-1];
                } else {    // i~j不是回文串
                    f[i][j] = false;
                }

                // i~j是回文串，且长度更大，更新答案
                if (f[i][j] && j-i+1 > maxLen) {
                    begin = i;
                    maxLen = j-i+1;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};