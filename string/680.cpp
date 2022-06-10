/*
680. 验证回文字符串 Ⅱ
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
https://leetcode.cn/problems/valid-palindrome-ii/
*/

class Solution {
public:
    // 判断字符串s 第 l ~ r 之间的字符串是否是回文串
    bool isPalindrome(const string& s, int l, int r) {
        if (s.empty()) return true;
        
        int i = l;
        int j =  r;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        // 长度为0、1、2的字符串自然满足条件
        if (s.size() < 3) return true;

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) { // 若两头字符相同，继续向中心检查
                i++;
                j--;
            } else { // 否则，删除1个字符，并检查剩下的是否是回文串
                if (isPalindrome(s, i+1, j))    // 删除第i个字符
                    return true;
                if (isPalindrome(s, i, j-1))    // 删除第j个字符
                    return true;
                return false;
            }
        }

        return true;
    }
}; 
