class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(int i = 0; i < edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                adj[v].push_back(u);
        }
        
        vector<int>indeg(V, 0);
        for(int i = 0; i < V; i++){
            for(int &j : adj[i]){
                indeg[j]++;
            }
        }
        
        queue<int>q;
        vector<int>result;
        for(int i = 0; i < V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(int &neighbour: adj[node]){
                indeg[neighbour]--;
                if(indeg[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(result.size() != V) return {};
        return result;
    }
};