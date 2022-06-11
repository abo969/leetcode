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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // 原节点 -> 拷贝节点
        unordered_map<Node*, Node*> hash;

        queue<Node*> q;
        q.push(node);

        // 复制入口节点
        Node* n = new Node(node->val);
        hash[node] = n;

        // BFS遍历并复制
        while (!q.empty()) {
            Node* p = q.front(); q.pop();

            // 复制邻接点并入队
            for (int i = 0; i < p->neighbors.size(); i++) {
                Node* u = p->neighbors[i];
                if (hash.find(u) == hash.end()) {
                    hash[u] = new Node(u->val); // 复制该节点
                    q.push(u);                  // 入队
                }
                // 构建邻接数组
                hash[p]->neighbors.emplace_back(hash[u]);
            }
        }

        return hash[node];
    }
}