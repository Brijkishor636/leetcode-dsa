class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int maxi = 0;
        int prefix = 0;
        for(int i = 0; i < arr.size()-1; i++){
            prefix = arr[i] + arr[i+1];
            maxi = max(prefix, maxi);
        }
        return maxi;
    }
};