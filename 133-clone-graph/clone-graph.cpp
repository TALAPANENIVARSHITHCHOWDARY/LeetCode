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
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_map<Node*, Node*> cloneMap; // Original to cloned node mapping
        
        // Create the root node of the cloned graph
        Node* cloneRoot = new Node(node->val);
        cloneMap[node] = cloneRoot;
        
        // BFS
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            // Iterate through neighbors
            for (Node* neighbor : current->neighbors) {
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    // Clone the neighbor if it hasn't been cloned yet
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Add the cloned neighbor to the current node's clone
                cloneMap[current]->neighbors.push_back(cloneMap[neighbor]);
            }
        }
        
        return cloneRoot;
    }
};