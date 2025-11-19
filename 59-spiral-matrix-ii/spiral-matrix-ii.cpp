class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir = 0;
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        vector<vector<int>>result(n, vector<int>(n, 0));
        int count = 1;
        while(top <= down && left <= right){
            if(dir == 0){
                for(int i = left; i <= right; i++){
                    result[top][i] = count;
                    count++;
                }
                top++;
            }
            if(dir == 1){
                for(int i = top; i <= down; i++){
                    result[i][right] = count;
                    count++;
                }
                right--;
            }
            if(dir == 2){
                for(int i = right; i >= left; i--){
                    result[down][i] = count;
                    count++;
                }
                down--;
            }
            if(dir == 3){
                for(int i = down; i >= top; i--){
                    result[i][left] = count;
                    count++;
                }
                left++;
            }
            dir++;
            if(dir == 4){
                dir = 0;
            }
        }
        return result;
    }
};