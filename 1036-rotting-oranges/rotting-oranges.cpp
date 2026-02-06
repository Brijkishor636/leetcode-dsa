class Solution {
public:
    bool possible(int x, int y, vector<vector<int>>& grid){
        return (x >= 0 && x < grid.size() &&
                y >= 0 && y < grid[0].size() &&
                grid[x][y] == 1);
    }

    int rottanOranges(vector<vector<int>>& grid, queue<pair<int, int>>& q, int &count){
        int time = 0;

        while(!q.empty()){
            int n = q.size();
            bool rottedThisRound = false;

            while(n--){
                auto node = q.front();
                q.pop();

                int x = node.first;
                int y = node.second;

                if(possible(x+1, y, grid)){
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                    count--;
                    rottedThisRound = true;
                }
                if(possible(x, y+1, grid)){
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                    count--;
                    rottedThisRound = true;
                }
                if(possible(x-1, y, grid)){
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                    count--;
                    rottedThisRound = true;
                }
                if(possible(x, y-1, grid)){
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                    count--;
                    rottedThisRound = true;
                }
            }

            if(rottedThisRound)
                time++;
        }

        if(count > 0) return -1;
        return time;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    count++;
            }
        }

        if(count == 0) return 0;

        return rottanOranges(grid, q, count);
    }
};
