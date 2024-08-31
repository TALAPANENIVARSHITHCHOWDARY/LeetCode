class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        vector<double> prob(n,0.0);
        prob[start_node]=1.0;
        while(!pq.empty()){
            double cp=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==end_node){
                return cp;
            }
            for(auto& [nn,ep]:adj[node]){
                double np=cp*ep;
                if(np>prob[nn]){
                    prob[nn]=np;
                    pq.push({np,nn});
                }
            }
        }
        return 0.0;
    }
};