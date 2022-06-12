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
class Solution {
public:
    int dfs(TreeNode* root, int maxVal) {
        if (!root) return 0;    // 树为空

        int total = 0;
        if (root->val >= maxVal) {
            maxVal = root->val;
            total++;
        }
        if (root->left) {       // 有左子树
            total += dfs(root->left, maxVal);
        }

        if (root->right) {      // 有右子树
            total += dfs(root->right, maxVal);
        }

        return total;
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;    // 树为空

        // 只有根节点（无左、右子树）
        if (!root->left && !root->right) return 1;

        int maxVal = root->val;
        return dfs(root, maxVal);
    }
};