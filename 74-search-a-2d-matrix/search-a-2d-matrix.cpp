class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int e = m*n - 1;
        while(s <= e){
            int mid = s + (e-s)/2;
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                e = mid - 1;
            }
            else 
                s = mid + 1;
        }
        return false;


        // int row = -1;
        // int rowNo = matrix.size();
        // int n = matrix[0].size();
        // for(int i = 0; i < rowNo; i++){
        //     if(matrix[i][0] <= target && matrix[i][n-1] >= target){
        //         row = i;
        //     }
        // }
        // if(row == -1){
        //     return false;
        // }
        // int s = 0;
        // int e = n-1;
        // while(s <= e){
        //     int mid = s + (e-s)/2;
        //     if(matrix[row][mid] == target){
        //         return true;
        //     }
        //     else if(matrix[row][mid] > target){
        //         e = mid-1;
        //     }
        //     else{
        //         s = mid + 1;
        //     }
        // }
        // return false;
    }
};