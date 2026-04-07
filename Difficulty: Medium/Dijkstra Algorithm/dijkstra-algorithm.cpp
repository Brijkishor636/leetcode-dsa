class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>>adj(V);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int>dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int d = top.first;
            int node = top.second;

            if (d > dist[node]) continue;

            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};