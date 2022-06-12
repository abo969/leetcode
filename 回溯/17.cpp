/**
 * 17. 电话号码的字母组合
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
public:
    vector<vector<char>> dic = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };

    void dfs(const string& s, int pos, string& cur, vector<string>& v) {
        if (cur.size() == s.size()) {   // 已将处理了n个数字
            v.emplace_back(cur);
            return;
        }

        int i = s[pos] - '0';           // 该数字对应dic字典中的index
        for (int j = 0; j < dic[i].size(); j++) {
            cur.push_back(dic[i][j]);   // 选择
            dfs(s, pos + 1, cur, v);    // 递归选择下一个字符
            cur.pop_back();             // 恢复
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        string cur;
        dfs(digits, 0, cur, res);
        return res;
    }
};