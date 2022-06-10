/*
516. 最长回文子序列
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
https://leetcode.cn/problems/longest-palindromic-subsequence/
*/

#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    if (s.size() < 2) return s.size();

    int n = s.size();
    vector<vector<int>> f(n, vector<int>(n));

    // 每个字符本身就是回文子序列
    for (int i = 0; i < n; i++) f[i][i] = 1;

    // 动态规划，f[i][j]: 第i ~ j个字符间最长回文子序列长度
    for (int i = n-2; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j])
                f[i][j] = f[i+1][j-1] + 2;
            else
                f[i][j] = max(f[i+1][j], f[i][j-1]);
        }
    }

    return f[0][n-1];
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}