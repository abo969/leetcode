class Solution {
public:
    bool isPalindrome(const string& s) {
        if (s.empty()) return true;
        
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    string shortestPalindrome(string s) {
        if (s.empty()) return s;

        // 边界：如果s本身是回文串，直接返回s本身
        if (isPalindrome(s)) return s;

        // 否则，从倒数第2个字符开始找s前面最长的回文串
        for (int j = s.size() - 2; j >= 0; j--) {
            string s1 = s.substr(0, j+1);
            if (isPalindrome(s1)) {
                string s2 = s.substr(j+1);
                std::reverse(s2.begin(), s2.end());
                return s2 + s;
            }
        }

        return s;
    }
};