#include <vector>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

class Solution {
public:
// Function to perform Dijkstra's algorithm to find the shortest path from 0 to n-1
        int dijkstra(int n, const vector<vector<int>>& adj){
            vector<int> dist(n, INT_MAX);
            dist[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();
                
                if (d > dist[u]) continue;
                
                for (int v : adj[u]) {
                    if (dist[u] + 1 < dist[v]) {
                        dist[v] = dist[u] + 1;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            return dist[n - 1];
        }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        // Initialize the graph with the initial unidirectional roads
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }
        
        vector<int> answer;
        
        
        
        // Process each query
        for (auto query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            answer.push_back(dijkstra(n, adj));
        }
        
        return answer;
    }
};
