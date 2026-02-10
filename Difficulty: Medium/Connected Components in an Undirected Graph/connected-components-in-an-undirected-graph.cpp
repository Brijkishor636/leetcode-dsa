class Solution {
  public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&visited, vector<int>&comp){
        visited[node] = 1;
        comp.push_back(node);
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adj, visited, comp);
            }
        }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int>visited(V, 0);
        vector<vector<int>>result;
        vector<vector<int>>adj(V);
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>comp;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, comp);
                result.push_back(comp);
                comp.clear();
            }
        }
        return result;
    }
};
