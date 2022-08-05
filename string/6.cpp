/**
 * 6. Z 字形变换
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 请你实现这个将字符串进行指定行数变换的函数：
 * string convert(string s, int numRows);
 * https://leetcode.cn/problems/zigzag-conversion/
 */
class Solution {
public:
    string convert(string s, int r) {
        if (s.empty()) return s;

        // 如果只输出1行，或者行数大于字符个数，直接输出原字符串
        int n = s.size();
        if (r == 1 || r >= n) return s;

        vector<vector<char>> v(r, vector<char>(n, 0));

        int cur = 0;
        int j = 0;
        while (cur < n) {
            // 向下走
            for (int i = 0; i < r; i++) {
                v[i][j] = s[cur++];
                if (cur >= n) break;
            }
            if (cur >= n) break;
            j++;

            // 向右上角走
            for (int i = r - 2; i > 0; i--) {
                v[i][j++] = s[cur++];
                if (cur >= n) break;
            }
        }

        string t = "";
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++)
                if (v[i][j]) t.push_back(v[i][j]);
        }

        return t;
    }
};