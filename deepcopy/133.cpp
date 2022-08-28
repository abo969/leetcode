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

        // BFS访问的队列
        queue<Node*> q;
        q.push(node);

        // BFS遍历图的每个节点并复制
        while (!q.empty()) {
            Node* p = q.front(); q.pop();

            if (!hash.count(p)) {   // 如果还没有复制该节点
                // 复制这个节点
                Node* n = new Node(p->val);
                hash[p] = n;

                // 邻接点入队
                for (int i = 0; i < p->neighbors.size(); i++) {
                    Node* u = p->neighbors[i];
                    // 未复制的节点才会继续入队
                    if (!hash.count(u)) q.push(u);
                }
            }
        }

        unordered_map<Node*, bool> visit;

        // BFS遍历图的每个节点为复制的图构建邻接点数组
        q.push(node);
        while (!q.empty()) {
            Node* p = q.front(); q.pop();
            if (visit[p]) continue;
            
            visit[p] = true;

            for (int i = 0; i < p->neighbors.size(); i++) {
                Node* u = p->neighbors[i];
                // 构建复制节点的邻接数组
                hash[p]->neighbors.push_back(hash[u]);
                // 未复制的节点才会继续入队
                if (!visit[u]) q.push(u);
            }
        }

        return hash[node];
    }
};