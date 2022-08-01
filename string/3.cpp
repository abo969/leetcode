/**
 * 3. 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 */

class Solution {
public:
    // 滑动窗口
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int n = s.size();
        unordered_set<char> st; // 判断是否出现过

        // 滑动窗口，左指针：l，右指针：r
        // 从第1个字符开始
        int l = 0;
        int r = -1;                 // r从-1开始，方便窗口右移
        int ans = 0;

        for (l = 0; l < n; l++) {
            if (l > 0)
                st.erase(s[l-1]);   // 窗口left右移，删除窗口前一个字符

            // 如果s[r]在set未出现过，窗口right右移扩大子串
            while (r+1 < n && st.count(s[r+1]) == 0) {
                st.insert(s[r+1]);
                r++;
            }

            // 当前无重复字符串最大长度
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};