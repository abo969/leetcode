/**
 * 133. 克隆图
 * 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
 * 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
 * class Node {
 *     public int val;
 *     public List<Node*> neighbors;
 * }
 * https://leetcode.cn/problems/clone-graph/
 *
 * Definition for a Node.
 * class Node {
 * public:
 *     int val;
 *     vector<Node*> neighbors;
 *     Node() {
 *         val = 0;
 *         neighbors = vector<Node*>();
 *     }
 *     Node(int _val) {
 *         val = _val;
 *         neighbors = vector<Node*>();
 *     }
 *     Node(int _val, vector<Node*> _neighbors) {
 *         val = _val;
 *         neighbors = _neighbors;
 *     }
 * };
*/

class Solution {
public:
    // 原节点 -> 拷贝节点
    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (hash.find(node) != hash.end()) return hash[node];

        // 复制该节点
        Node* clone = new Node(node->val);
        hash[node] = clone;

        // 递归处理邻接点
        for (auto& u : node->neighbors) {
            clone->neighbors.emplace_back(cloneGraph(u));
        }

        return clone;
    }
};