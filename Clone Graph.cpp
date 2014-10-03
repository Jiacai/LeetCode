/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        return cloneGraphRe(node ,visited);
    }
    
    UndirectedGraphNode *cloneGraphRe(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*> &visited) {
        if (node == NULL)
            return NULL;
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        visited[node] = newnode;
        for (auto iter = node->neighbors.begin(); iter != node->neighbors.end(); iter++) {
            UndirectedGraphNode * sub = cloneGraphRe(*iter, visited);
            newnode->neighbors.push_back(sub);
        }
        return newnode;
    }
};
