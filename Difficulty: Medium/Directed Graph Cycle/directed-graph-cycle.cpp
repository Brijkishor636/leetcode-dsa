/* class Solution {
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
*/

class Solution {
  public:
    bool dfsCheck(int node, vector<bool>&visited, vector<bool>&pathVisited, vector<vector<int>>&adj){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfsCheck(it, visited, pathVisited, adj)){
                    return true;
                }
            }
            else if(pathVisited[it])
                return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<bool>visited(V, 0);
        vector<bool>pathVisited(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfsCheck(i, visited, pathVisited, adj))
                    return true;
            }
        }
        return false;
    }
};



