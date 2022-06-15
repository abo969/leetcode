/**
 * 7. 整数反转
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。 
 * https://leetcode.cn/problems/reverse-integer/
 */

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        int res = 0;
        while (x) {
            // 防止越界
            if (res > INT_MAX / 10 || res < INT_MIN / 10)
                return 0;
            
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }
}