/**
 * 94. 二叉树的中序遍历
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/ 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* p = root;
        while (p || !st.empty()) {      // p为空、但栈不空时，处理“根”节点
            while (p) {                 // 找到左子树并入栈直到最左边的叶子节点
                st.push(p);
                p = p->left;
            }

            p = st.top(); st.pop();     // 出栈，这里会弹出上面的”根“节点并访问
                                        // 从而控制：左子树、根、右子树
            res.emplace_back(p->val);   // 加入结果k集
            p = p->right;               // 处理右子树，可能为空，但栈不一定空
        }

        return res;
    }
};