class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});
        vector<bool>visited(V, false);
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(visited[node] == true){
                continue;
            }
            visited[node] = true;
            sum += wt;
            
            for(auto neighbour: adj[node]){
                int adjNode = neighbour.first;
                int adjwt = neighbour.second;
                if(!visited[adjNode]){
                    pq.push({adjwt, adjNode});
                }
            }
        }
        return sum;
    }
};