class Solution {
  public:
    int maximizeMoney(int N, int K) {
        int n = N;
        vector<int>arr(n+1, 0);
        arr[0] = 0;
        arr[1] = K;
        for(int i = 2; i <= n; i++){
            int steal = arr[i-2] + K;
            int skip = arr[i-1];
            arr[i] = max(steal, skip);
        }
        return arr[n];
    }
};