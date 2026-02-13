class Solution {
  public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&s){
        visited[node] = 1;
        for(int &neighbour: adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited, s);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        stack<int>s;
        vector<bool>visited(V, 0);
        for(int i = 0; i < edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
        }
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, s);
            }
        }
        vector<int>result;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            result.push_back(top);
        }
        return result;
    }
};