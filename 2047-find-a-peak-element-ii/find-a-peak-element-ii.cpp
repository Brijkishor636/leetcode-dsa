class Solution {
public:
    int maxElement(vector<vector<int>>&mat, int mid){
        int n = mat.size();
        int maxi = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mat[i][mid] > maxi){
                maxi = mat[i][mid];
                ans = i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int s = 0;
        int m = mat[0].size();
        int e = m-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            int row = maxElement(mat, mid);
            int left = (mid-1) >= 0 ? mat[row][mid-1] : -1;
            int right = (mid+1) < m ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(mat[row][mid] < left){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return {-1, -1};
    }
};