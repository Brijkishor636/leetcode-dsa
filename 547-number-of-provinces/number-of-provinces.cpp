class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int node, vector<bool>&visited){
        visited[node] = true;
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[node][j] == 1 && !visited[j]){
                dfs(isConnected, j, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int v = isConnected.size();
        vector<bool>visited(v, false);
        
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};