/**
 * 2. 两数相加
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * https://leetcode.cn/problems/add-two-numbers/ 
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;      // 进位
        while (p || q) {
            int a = p ? p->val : 0;
            int b = q ? q->val : 0;
            int sum = a + b + carry;            // 同位求和
            cur->next = new ListNode(sum % 10); // 创建新节点
            cur = cur->next;
            carry = sum / 10;                   // 重新计算进位

            if (p) p = p->next;
            if (q) q = q->next;
        }
        
        // 处理最后的进位
        if (carry) cur->next = new ListNode(carry);
        return dummy->next;
    }
};