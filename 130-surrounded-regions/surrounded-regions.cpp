class Solution {
public:
    bool possible(int x, int y,vector<vector<bool>>&visited, vector<vector<char>>& board){
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && visited[x][y] == 0 && board[x][y] == 'O');
    }
    void dfs(int x, int y, vector<vector<bool>>&visited, vector<vector<char>>& board){
        visited[x][y] = 1;
        if(possible(x+1, y,visited, board)){
            dfs(x+1, y, visited, board);
        }
        if(possible(x-1, y,visited, board)){
            dfs(x-1, y, visited, board);
        }
        if(possible(x, y+1,visited, board)){
            dfs(x, y+1, visited, board);
        }
        if(possible(x, y-1,visited, board)){
            dfs(x, y-1, visited, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, 0));
        
        for(int i = 0; i < row; i++) {
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, visited, board);

            if(board[i][col-1] == 'O' && !visited[i][col-1])
                dfs(i, col-1, visited, board);
        }

        for(int j = 0; j < col; j++) {
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, visited, board);

            if(board[row-1][j] == 'O' && !visited[row-1][j])
                dfs(row-1, j, visited, board);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(visited[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};