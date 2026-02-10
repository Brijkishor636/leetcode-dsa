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

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>visited(n, 0);
        int count = 0;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vector<int>comp;
                dfs(i, adj, visited, comp);

                int k = comp.size();
                int edgeCount = 0;
                for(int node: comp){
                    edgeCount += adj[node].size();
                }
                edgeCount = edgeCount / 2;
                if(edgeCount == k * (k-1)/2){
                    count++;
                }
            }
        }
        return count;
    }
};