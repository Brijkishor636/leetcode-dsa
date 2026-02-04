class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<int>result;
        vector<bool>visited(v, 0);
        queue<int>q;
        visited[0] = 1;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(int i = 0; i < adj[node].size(); i++){
                int neighbour = adj[node][i];
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        return result;
    }
};