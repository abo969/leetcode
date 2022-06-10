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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() < 2) return 1;

        int n = s.size();
        int ans = n;    // 每一个字符单独为回文串

        // 考虑回文串长度为奇数：以每个字符为中心向左右拓展
        for (int i = 0; i < n; i++) {
            // 枚举长度，并从i位置向左、右伸展
            for (int l = 1; l <= n/2; l++) {
                // 判断边界
                if (i - l < 0 || i + l >= n) break;
                if (s[i-l] != s[i+l]) break;
                ans++;
            }
        }

        // 考虑回文串长度为偶数：以每两个相邻字符为中心向左右拓展
        for (int i = 0; i < n-1; i++) {
            if (s[i] != s[i+1]) continue;
            
            ans++;
            // 枚举长度，并从i位置向左、右伸展
            for (int l = 1; l < n/2; l++) {
                // 判断边界
                if (i - l < 0 || i + l + 1 >= n) break;
                if (s[i-l] != s[i+1+l]) break;
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    string x;
    cin >> x;
    cout << s.countSubstrings(x) << endl;
    return 0;
}