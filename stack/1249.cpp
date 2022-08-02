/**
 * 1249. 移除无效的括号
 * 给你一个由 '('、')' 和小写字母组成的字符串 s。
 * 你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。
 * 请返回任意一个合法字符串。
 * 有效「括号字符串」应当符合以下 任意一条 要求：
 * 空字符串或只包含小写字母的字符串
 * 可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
 * 可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 * https://leetcode.cn/problems/minimum-remove-to-make-valid-parentheses/
 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string t;

        for (auto c : s) {
            if (c == '(') {             // '('，入栈
                st.push(c);
                t.push_back(c);
            } else if (c == ')') {
                if (!st.empty()) {      // 如果栈不为空，该')'有效，留下
                    st.pop();           // 栈顶出战
                    t.push_back(c);     // 不为空说明匹配，留下
                }                       // 如果栈为空，该')'无效，删除，即不保存到t
            } else {                    // 字符，留下
                t.push_back(c);
            }
        }

        while (!st.empty()) {           // 删除多余的(，如 ))((
            char c = st.top();
            st.pop();
            size_t pos = t.find_last_of(c);
            if (pos != string::npos) t.erase(pos, 1);
        }
        return t;
    }
};