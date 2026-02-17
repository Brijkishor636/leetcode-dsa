class Solution {
public:
    bool dfs(int node, vector<bool>&visited, vector<bool>&pathVisited, vector<vector<int>>&adj){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfs(it, visited, pathVisited, adj))
                    return true;
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(V);
        vector<bool>visited(V, 0);
        vector<bool>pathVisited(V, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(i, visited, pathVisited, adj))
                    return false;
            }
        }
        return true;
    }
};