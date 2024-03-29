/**
 * 1485. 克隆含随机指针的二叉树
 * 给你一个二叉树，树中每个节点都含有一个附加的随机指针，该指针可以指向树中的任何节点或者指向空（null）。
 * 请返回该树的 深拷贝 。
 * 该树的输入/输出形式与普通二叉树相同，每个节点都用 [val, random_index] 表示：
 * val：表示 Node.val 的整数
 * random_index：随机指针指向的节点（在输入的树数组中）的下标；如果未指向任何节点，则为 null 。
 * 该树以 Node 类的形式给出，而你需要以 NodeCopy 类的形式返回克隆得到的树。NodeCopy 类和Node 类定义一致。
 * 
 * https://leetcode.cn/problems/clone-binary-tree-with-random-pointer/
 */

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (!root) return nullptr;

        unordered_map<Node*, NodeCopy*> hash;
        queue<Node*> q;
        q.push(root);

        // BFS遍历二叉树的每个节点并复制
        while (!q.empty()) {
            Node* p = q.front(); q.pop();

            if (!hash.count(p)) {                       // 如果还没有复制该节点
                NodeCopy* node = new NodeCopy(p->val);  // 复制该节点
                hash[p] = node;
            }

            // 复制儿子节点
            if (p->left && !hash.count(p->left)) {
                hash[p->left] = new NodeCopy(p->left->val);
                q.push(p->left);
            }

            if (p->right && !hash.count(p->right)) {
                hash[p->right] = new NodeCopy(p->right->val);
                q.push(p->right);
            }

            if (p->random && !hash.count(p->random)) {
                hash[p->random] = new NodeCopy(p->random->val);
                q.push(p->random);
            }

            // 为新树的left、right、random赋值
            hash[p]->left = p->left ? hash[p->left] : nullptr;
            hash[p]->right = p->right ? hash[p->right] : nullptr;
            hash[p]->random = p->random ? hash[p->random] : nullptr;
        }

        return hash[root];
    }
};
