/**
 * 236. 二叉树的最近公共祖先
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
 * 最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度
 * 尽可能大（一个节点也可以是它自己的祖先）。”
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> father;

    // 构建父节点hash表
    void dfs(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            father[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            father[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        father[root->val] = nullptr;
        dfs(root);                              // 构建父节点hash表

        unordered_map<TreeNode*, bool> visit;   // 已访问hash表

        TreeNode* fa = p;
        while (fa) {                            // 向上爬，记录p节点的父节点
            visit[fa] = true;
            fa = father[fa->val];
        }

        // 类似爬树，向上爬的过程中，若先遇到一个以访问节点，即为LCA
        fa = q;
        while (fa) {
            if (visit[fa]) return fa;
            fa = father[fa->val];
        }

        return root;        // visit表里没找到，返回根节点
    }
};