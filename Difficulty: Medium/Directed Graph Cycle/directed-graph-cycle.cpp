class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>indeg(V, 0);
        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][1];
            indeg[v]++;
        }
        
        queue<int>q;
        int count = 0;
        for(int i = 0; i < V; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        if(count == V){
            return false;
        }
        return true;
    }
};

