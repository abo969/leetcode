/*
459. 重复的子字符串
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

来源：力扣（LeetCode）
链接： https://leetcode.cn/problems/repeated-substring-pattern/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty()) return false;

        int n = s.size();
        // 枚举长度为l的子串，l的最大长度不会超过n/2
        for (int l = 1; l <= n / 2; l++) {
            if (n % l) continue;    // 如果长度l不能构成长度为n的串

            bool matched = true;
            for (int j = l; j < n; j++) {
                if (s[j - l] != s[j]) { // 有一个不匹配，跳过
                    matched = false;
                    break;
                }
            }

            // 是否匹配
            if (matched) return true;
        }

        return false;
    }
};