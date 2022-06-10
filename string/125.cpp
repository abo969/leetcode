/*
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
https://leetcode.cn/problems/valid-palindrome/
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
     
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }

            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }

        return true;
    }
};