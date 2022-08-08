/**
 * 1669. 合并两个链表
 * 给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
 * 请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。
 * https://leetcode.cn/problems/merge-in-between-linked-lists/
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1;
        ListNode* pre = list1;

        int step = 0;
        while (step < a) {      // 走到a，pre指向a前一个节点
            pre = p;
            p = p->next;
            step++;
        }

        while (step < b) {      // 走到b，p指向b节点
            p = p->next;
            step++;
        }

        ListNode* q = list2;
        pre->next = list2;      // 链接list2
        while (q) {             // 找到list2点尾结点，q指向尾结点
            q = q->next;
            if (!q->next) break;
        }

        q->next = p->next;      // 链接list1剩余的部分
        return list1;
    }
};