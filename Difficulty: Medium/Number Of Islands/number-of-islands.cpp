// User function Template for C++
class Solution {
  public:
    int findParent(int x, vector<int>&parent){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findParent(parent[x], parent);
    }
    
    void unionBySize(int x, int y, vector<int>&parent, vector<int>&rank){
        int x_parent = findParent(x, parent);
        int y_parent = findParent(y, parent);
        if(x_parent == y_parent) return;
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    bool isValid(int row, int col, int n, int m){
        return (row < n && row >= 0 && col >= 0 && col < m);
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int visited[n][m];
        memset(visited, 0, sizeof visited);
        int count = 0;
        vector<int>ans;
        vector<int> parent(n * m);
        vector<int> rank(n * m, 0);
        for(int i = 0; i < n * m; i++){
            parent[i] = i;
        }
        
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(visited[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            visited[row][col] = 1;
            count++;
            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};
            for(int i = 0; i < 4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(isValid(nrow, ncol, n, m)){
                    if(visited[nrow][ncol] == 1){
                        int NodeNo = row * m + col;
                        int adjNodeNo = nrow * m + ncol;
                        if(findParent(NodeNo, parent) != findParent(adjNodeNo, parent)){
                            unionBySize(NodeNo, adjNodeNo, parent, rank);
                            count--;
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
