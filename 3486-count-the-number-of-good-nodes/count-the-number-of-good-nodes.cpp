class Solution {
public:
    // DFS helper function to calculate subtree sizes and count good nodes
    int dfs(int node, int parent, vector<vector<int>>& adj, int& goodNodesCount) {
        int subtreeSize = 1;  // Every node counts as size 1 (itself)
        unordered_set<int> childSizes;

        for(int child : adj[node]) {
            if(child == parent) continue;  // Skip the parent node

            int childSize = dfs(child, node, adj, goodNodesCount);
            childSizes.insert(childSize);
            subtreeSize += childSize;
        }

        // A node is "good" if all children have the same subtree size
        if(childSizes.size() <= 1) {
            goodNodesCount++;
        }

        return subtreeSize;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        // Build the adjacency list
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Initialize the count of good nodes
        int goodNodesCount = 0;

        // Start DFS from the root node (node 0)
        dfs(0, -1, adj, goodNodesCount);

        return goodNodesCount;
    }
};