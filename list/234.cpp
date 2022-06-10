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
    bool isPalindrome(vector<int>& v) {
        int i = 0;
        int j = v.size() - 1;
        while (i < j) {
            if (v[i] != v[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        vector<int> v;
        auto p = head;
        while (p) {
           v.push_back(p->val);
           p = p->next;
        }

        return isPalindrome(v);
    }
};