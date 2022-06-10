/**
 * 92. 反转链表 II
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
 * 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 * https://leetcode.cn/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;

        if (left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 找到left节点前的一个节点pre，pre不变
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; i++) pre = pre->next;

        // cur指向left节点，且不变
        ListNode* cur = pre->next;
        for (int i = left; i < right; i++) {
            ListNode* p = cur->next;
            // 将p插入pre后的第一个位置
            cur->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }

        return dummy->next;
    }
};