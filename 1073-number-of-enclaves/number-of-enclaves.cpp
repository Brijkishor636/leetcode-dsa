class Solution {
public:
    bool isPossible(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&visited){
        return (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1 && visited[row][col] == 0);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        int delrow[] = {+1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // if(isPossible(row+1, col, grid, visited)){
            //     q.push({row+1, col});
            //     visited[row+1][col] = 1;
            // }
            // if(isPossible(row-1, col, grid, visited)){
            //     q.push({row-1, col});
            //     visited[row-1][col] = 1;
            // }
            // if(isPossible(row, col+1, grid, visited)){
            //     q.push({row, col+1});
            //     visited[row][col+1] = 1;
            // }
            // if(isPossible(row, col-1, grid, visited)){
            //     q.push({row, col-1});
            //     visited[row][col-1] = 1;
            // }

            for(int i = 0; i < 4; i++){
                int nrow = row+delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};