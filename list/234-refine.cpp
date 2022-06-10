/**
 * 234. 回文链表
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * https://leetcode.cn/problems/palindrome-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* p = cur->next;
            cur->next = pre;
            pre = cur;
            cur = p;
        }

        return pre;
    }

    // 通过快慢指针找到前半部分的最后一个节点
    ListNode* endofFirstHalf(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 找到前半部分链表的最后一个节点
        ListNode* endNode = endofFirstHalf(head);
        // 翻转后半部分链表
        ListNode* q = reverseList(endNode->next);

        ListNode* p = head;
        while (q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};