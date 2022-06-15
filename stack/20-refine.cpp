/**
 * 20. 有效的括号
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。 
 * https://leetcode.cn/problems/valid-parentheses/
 */

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n == 0) return true;
        if (n % 2 == 1) return false;

        unordered_map<char, char> matched = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> stk;
        for (char c : s) {
            if (matched.count(c)) { // 右括号，判断是否匹配
                if (stk.empty())    // 栈为空，不匹配
                    return false;

                if (stk.top() != matched[c])    // 不匹配
                    return false;

                stk.pop();          // 匹配，栈顶出栈

            } else {                // 左括号，入栈
                stk.push(c);
            }
        }

        return stk.empty();         // 栈为空，说明匹配完成；否则不匹配
    }
};