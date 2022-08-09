/**
 * 23. 合并K个升序链表
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * https://leetcode.cn/problems/merge-k-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ((!l1) || (!l2)) return l1 ? l1 : l2;

        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (p && q) {
            if (p->val <= q->val) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
            
            cur = cur->next;
        }

        cur->next = p ? p : q;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for (int i = 0; i < lists.size(); i++)
            res = mergeTwoLists(res, lists[i]);
        
        return res;
    }
};