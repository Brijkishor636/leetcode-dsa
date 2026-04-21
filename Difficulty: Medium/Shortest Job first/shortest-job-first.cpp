

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        int n = bt.size();
        vector<int>sum(n, 0);
        sum[0] = bt[0];
        for(int i = 0; i < n-1; i++){
            sum[i+1] = bt[i+1] + sum[i];
        }
        long long wt = 0;
        for(int i = 0; i < n-1; i++){
            wt += sum[i];
        }
        return wt/n;
    }
};