/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    void rec(
        Node* root,
        unordered_map<Node*, bool>& visited,
        unordered_map<Node*, Node*>& nodeMap
    ){
        if(root == NULL) return;
        visited[root] = true;

        if(nodeMap[root] == NULL){
            nodeMap[root] = new Node(root->val);
        }

        auto& currNode = nodeMap[root];

        for(auto& node: root->neighbors){
            if(nodeMap[node] == NULL){
                nodeMap[node] = new Node(node->val);
            }
            currNode->neighbors.push_back(nodeMap[node]);
            if(!visited[node]){
                rec(node, visited, nodeMap);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, bool> visited;
        unordered_map<Node*, Node*> nodeMap;

        rec(node, visited, nodeMap);

        return nodeMap[node];
    }
};
