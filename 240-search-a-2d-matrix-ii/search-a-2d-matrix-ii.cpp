class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int col = m-1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;

        // int row = matrix.size();
        // int n = matrix[0].size();
        // for(int i = 0; i < row; i++){
        //     int s = 0;
        //     int e = n-1;
        //     while(s <= e){
        //         int mid = s + (e-s)/2;
        //         if(matrix[i][mid] == target){
        //             return true;
        //         }
        //         else if(matrix[i][mid] > target){
        //             e = mid - 1;
        //         }
        //         else{
        //             s = mid + 1;
        //         }
        //     }
        // }
        // return false;
    }
};