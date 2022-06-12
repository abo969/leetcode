/**
 * @file 8.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class Solution {
public:
    const int INF = 2147483647;
    const int INF2 = 2147483648;

    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0;
        // 去掉前导空格
        while (i < s.size() && s[i] == ' ') i++;

        // 处理负号
        int sign = 1;
        if (s[i] == '-')  {
            sign = -1;
            i++;
        } else if (s[i] == '+')  {
            sign = 1;
            i++;
        }

        // 处理数字部分
        int ans = 0;
        while (i < s.size() && isdigit(s[i])) {
            int d = s[i] - '0';
            if (ans > INF / 10) return sign == -1 ? INF2 : INF;
            if (ans == INF / 10 && d > 7) return sign == -1 ? INF2 : INF;
            ans = ans * 10 + d;
            i++;
        }

        return sign == -1 ? -1 * ans : ans;
    }
};