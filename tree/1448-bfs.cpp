/**
 * 1448. 统计二叉树中好节点的数目
 * 给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。
 * 「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
 * https://leetcode.cn/problems/count-good-nodes-in-binary-tree/
 * 
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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;    // 树为空

        // 只有根节点（无左、右子树）
        if (!root->left && !root->right) return 1;

        queue<TreeNode*> qnode;     // 节点队列
        queue<int> qmax;            // 最大值队列

        qnode.push(root);
        qmax.push(root->val);

        int total = 0;
        while (!qnode.empty()) {
            TreeNode* node = qnode.front(); qnode.pop();
            int maxVal = qmax.front(); qmax.pop();

            if (node->val >= maxVal) total++;

            if (node->left) {
                qnode.push(node->left);
                qmax.push(max(maxVal, node->left->val));
            }

            if (node->right) {
                qnode.push(node->right);
                qmax.push(max(maxVal, node->right->val));
            }
        }

        return total;
    }
};