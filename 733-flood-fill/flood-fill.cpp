class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == originalColor) {

                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};
