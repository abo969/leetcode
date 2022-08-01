/**
 * 25. K 个一组翻转链表
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/ 
 */

/**
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
    int getNodeCount(ListNode* head) {
        if (!head) return 0;

        int cnt = 0;
        auto p = head;
        while (p) {
            cnt++;
            p = p->next;
        }

        return cnt;
    }

    ListNode* reverseKNode(ListNode* head, int k, ListNode** tail, ListNode** next) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        for (int i = 0; cur && i < k; i++) {
            ListNode* p = cur->next;
            cur->next = pre;
            pre = cur;
            cur = p;
        }

        *tail = head;   // 翻转k个节点后当前链表的k个节点的尾节点
        *next = cur;    // 翻转k个节点后的链表的第k+1个节点
        return pre;
    }

    ListNode* revereseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int cnt = getNodeCount(head);
        int (cnt < k) return head;

        ListNode* newhead;
        ListNode* newh;
        ListNode* ntail = new ListNode(0);
        ListNode* nnext = new ListNode(0);
        ListNode** tail = &ntail;
        ListNode** next = &nnext;
        ListNode* pretail;

        if (cnt >= k) {
            newh = reverseKNode(head, k, tail, next);
            newhead = newh;
            cnt -= k;
            pretail = *tail;
            pretail->next = next;
        }

        while (cnt >= k) {
            newh = reverseKNode(nnext, k, tail, next);
            pretail->next = newh;
            pretail = *tail;
            pretail->next = *next;
            cnt -= k;
        }

        return newhead;
    }