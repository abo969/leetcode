/**
 * 151. 颠倒字符串中的单词
 * 给你一个字符串 s ，颠倒字符串中 单词 的顺序。
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
 * 返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 * https://leetcode.cn/problems/reverse-words-in-a-string/
 */

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;

        s += " ";                   // 为统一处理在字符串最后加空格
        int start = 0;              // 单词起始位置
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && i > start)   // 新的单词产生
                st.push(s.substr(start, i - start));
            if (s[i] == ' ')        // 设置起始位置
                start = i + 1;
        }

        string t = "";
        while (!st.empty()) {
            t += st.top();
            st.pop();
            if (!st.empty())
                t += " ";
        }

        return t;
    }
};