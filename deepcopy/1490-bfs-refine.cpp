/**
 * 1490. 克隆 N 叉树
 * 给定一棵 N 叉树的根节点 root ，返回该树的深拷贝（克隆）。
 * N 叉树的每个节点都包含一个值（ int ）和子节点的列表（ List[Node] ）。
 * 
 * https://leetcode.cn/problems/clone-n-ary-tree/
 * 
 * Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node*> children;
    
        Node() {}
    
        Node(int _val) {
            val = _val;
        }
    
        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;

        unordered_map<Node*, Node*> hash;
        queue<Node*> q;
        q.push(root);

        // BFS遍历N叉树并复制节点
        while (!q.empty()) {
            Node* p = q.front(); q.pop();

            if (!hash.count(p)) {   // 复制该节点
                Node* node = new Node(p->val);
                hash[p] = node;
            }

            // 复制N个儿子节点并入队
            for (auto& u : p->children) {
                if (!hash.count(u)) {
                    hash[u] = new Node(u->val); // 复制
                    q.push(u);                  // 入队
                }
                hash[p]->children.emplace_back(hash[u]);
            }
        }

        return hash[root];
    }
};