// User function template for C++
class Solution {
  public:
    int left_occurance(vector<vector<int>>&arr, int row, int col){
        int s = 0;
        int e = col-1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[row][mid] == 1){
                e = mid-1;
                ans = mid;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
    
    int right_occurance(vector<vector<int>>&arr, int row, int col){
        int s = 0;
        int e = col-1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[row][mid] == 1){
                s = mid+1;
                ans = mid;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) {
        int row = arr.size();
        int col = arr[0].size();
        int maxi = 0;
        int ans = -1;
        int left = 0; 
        int right = 0;
        int count = 0;
        for(int i = 0; i < row; i++){
            if(left_occurance(arr, i, col) != -1)
                left = left_occurance(arr, i, col);
            if(right_occurance(arr, i, col) != -1)
                right = right_occurance(arr, i, col);
            if(left != 0 || right != 0){
                count = right-left+1;
            }
            if(count > maxi){
                maxi = count;
                ans = i;
            }
        }
        return ans;
    }
};