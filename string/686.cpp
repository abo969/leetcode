/*
686. 重复叠加字符串匹配
给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a
的子串，如果不存在则返回 -1。
注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/repeated-string-match
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();

        int minc = m / n;           // 最少复制次数
        int maxc = (m + n) / n + 1; // 最多复制次数

        // 复制minc次
        string s = "";
        for (int i = 0; i < minc; i++) s += a;

        // 剩余复制次数
        for (int i = minc; i <= maxc; i++) {
            string::size_type pos = s.find(b);
            if (pos != string::npos) return i; 
            s += a;
        }

        return -1;
    }
};