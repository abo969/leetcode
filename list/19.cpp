/**
 * 19. 删除链表的倒数第 N 个结点
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        int step = 0;
        ListNode* p = head;
        while (p) {         // p先走n步
            step++;
            p = p->next;
            if (step == n) break;
        }

        ListNode* pre = head;
        ListNode* q = head;
        while (p && q) {    // p、q一起走
            pre = q;
            p = p->next;
            q = q->next;
            //if (p->next == nullptr) // p到达结尾
            //    break;
        }

        // q->next就是倒数第n个节点
        if (q == head) head = head->next;
        else pre->next = q->next;
        return head;
    }
};