// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int row = mat.size();
//         int col = mat[0].size();
        
//         vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
//         queue<pair<int,int>> q;
        
//         for(int i = 0; i < row; i++){
//             for(int j = 0; j < col; j++){
//                 if(mat[i][j] == 0){
//                     dist[i][j] = 0;
//                     q.push({i, j});
//                 }
//             }
//         }

//         int dx[] = {1, -1, 0, 0};
//         int dy[] = {0, 0, 1, -1};
//        while(!q.empty()){
//             auto [r, c] = q.front();
//             q.pop();
            
//             for(int i = 0; i < 4; i++){
//                 int nr = r + dx[i];
//                 int nc = c + dy[i];
                
//                 if(nr >= 0 && nr < row && nc >= 0 && nc < col){
//                     if(dist[nr][nc] > dist[r][c] + 1){
//                         dist[nr][nc] = dist[r][c] + 1;
//                         q.push({nr, nc});
//                     }
//                 }
//             }
//         }
        
//         return dist;
//     }
// };


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dist(row, vector<int>(col, 0));
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>>visited(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0 && !visited[i][j]){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        while(!q.empty()){
            int rowfirst = q.front().first.first;
            int colfirst = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[rowfirst][colfirst] = steps;
            for(int i = 0; i < 4; i++){
                int nrow = rowfirst + delrow[i];
                int ncol = colfirst + delcol[i];
                if(nrow >=  0 && nrow < row && ncol >= 0 && ncol < col && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        
        return dist;
    }
};