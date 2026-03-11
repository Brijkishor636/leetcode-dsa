class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int i=0, j = 0; 
        int sum = 0;
        int maxi = 0;
        int n = arr.size();
        while(j < k){
            sum += arr[j];
            j++;
        }
        maxi = max(sum, maxi);
        while(j < n){
            sum = sum + arr[j] - arr[i];
            maxi = max(sum, maxi);
            i++;
            j++;
        }
        return maxi;
    }
};