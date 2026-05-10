class Solution {
  public:
    int solve(int n, vector<int>&arr, vector<int>&dp){
        if(n < 0) return 0;
        if(dp[n] != -1){
            return dp[n];
        }
        int steal = arr[n] + solve(n-2, arr, dp);
        int skip = solve(n-1, arr, dp);
        return dp[n] = max(steal, skip);
    }
    
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp1, temp2;
        vector<int>dp(n+1, -1);
        vector<int>dp2(n+1, -1);
        
        for(int i = 0; i < n-1; i++){
            temp1.push_back(arr[i]);
        }
        for(int i = 1; i < n; i++){
            temp2.push_back(arr[i]);
        }
        int case1 = solve(temp1.size()-1, temp1, dp);
        int case2 = solve(temp2.size()-1, temp2, dp2);
        return max(case1, case2);
    }
};
