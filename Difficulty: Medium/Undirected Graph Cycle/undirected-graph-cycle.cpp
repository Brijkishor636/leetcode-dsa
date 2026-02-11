class Solution {
  public:
    bool detectCycle(int src, vector<vector<int>>&adj, vector<int>&visited){
        visited[src] = 1;
        queue<pair<int, int>>q;
        q.push({src, 1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int adjecent: adj[node]){
                if(!visited[adjecent]){
                    visited[adjecent] = 1;
                    q.push({adjecent, node});
                }
                else if(adjecent != parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        vector<int>visited(V, 0);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(detectCycle(i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};