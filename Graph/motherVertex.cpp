//
// Problem Statement: https://practice.geeksforgeeks.org/problems/mother-vertex/1

class Solution {
  public:
    
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        
        vis[node] = 1;
        
        for(auto &v : adj[node]){
            
            if(!vis[v]){
                dfs(v, adj, vis);
            }
        }
    }
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int> adj[V];
        
        for(auto &q : edges){
            int u = q[0];
            int v = q[1];
            
            adj[u].push_back(v);
        }
        vector<int> vis(V, 0);
        
        int ans = -1;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans = i;
            }
        }
        
        // step-2
        fill(vis.begin(), vis.end(), 0);
        
        dfs(ans, adj, vis);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                return -1;
            }
        }
        return ans;
    }
};