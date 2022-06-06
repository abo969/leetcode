/*
28. 实现 strStr()
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的
第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java
的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int strStr(string sa, string sb) {
        if (sb.empty()) return 0;
        if (sb.size() > sa.size()) return -1;

        int n = sa.size();
        int m = sb.size();
        int i = 0, j = 0;
        int start = i;
        while (i < n) {
            // 先匹配sb[j]，sa从i开始，不匹配i向前走，找到sb[j]=sa[i]
            while (i < n && sb[j] != sa[i]) i++;

            start = i;  // 记录i

            // 匹配sa[i]、sb[j]，直到结束或者不匹配
            while (i < n && j < m && sa[i] == sb[j]) i++, j++;

            if (j < m)  // 如果sb没结束，sb从头、sa从下一个位置开始匹配
                j = 0, i = start + 1;
            else        // 如果sb结束了，说明找到一个匹配，直接返回
                return start;
        }

        // 没有找到任何匹配
        return -1;
    }
};