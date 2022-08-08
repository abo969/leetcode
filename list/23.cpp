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
    struct Node {
        int val;            // 链表头节点的值
        ListNode* head;     // 链表头节点

        bool operator<(const Node& node) const {
            return val > node.val;
        }
    };

    priority_queue<Node> q; // 优先队列，默认小根堆

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto it : lists)
            if (it) q.push({it->val, it});

        ListNode* dummy= new ListNode(0);
        ListNode* cur = dummy;
        while (!q.empty()) {
            auto p = q.top();   // 访问该链表
            q.pop();

            cur->next = p.head;
            cur = cur->next;
            if (p.head->next)   // 如果该链表后面还有节点，添加到队列
                q.push({p.head->next->val, p.head->next});
        }

        return dummy->next;
    }
};