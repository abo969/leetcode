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
    unordered_map<Node*, Node*> hash;

    Node* cloneTree(Node* root) {
        if (!root) return nullptr;

        if (hash.find(root) != hash.end())
            return hash[root];

        // 复制该节点
        Node* node = new Node(root->val);
        hash[root] = node;

        // 复制每个儿子节点
        for (auto& u : root->children) {
            node->children.emplace_back(cloneTree(u));
        }

        return node;
    }
};