// class Solution {
//   public:
//     int solve(vector<int>& bt) {
//         int n = bt.size();
//         sort(bt.begin(), bt.end());
//         vector<int>prefix(n, 0);
//         prefix[0] = bt[0];
//         for(int i = 1; i < n; i++){
//             prefix[i] = bt[i] + prefix[i-1];
//         }
//         int sum = 0;
//         for(int i = 0; i < n-1; i++){
//             sum += prefix[i];
//         }
//         return sum / n;
//     }
// };


class Solution {
  public:
    int solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        int t = 0, wt = 0;
        for(int i = 0; i < n; i++){
            wt += t;
            t += bt[i];
        }
        return (wt/n);
    }
};