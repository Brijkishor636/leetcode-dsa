class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<double>>ans;
        for(int i = 0; i < n; i++){
            double ratio = (double)val[i] / wt[i];
            ans.push_back({(double)val[i], (double)wt[i], ratio});
        }
        double result = 0;
        
        sort(ans.begin(), ans.end(), [](vector<double>&a, vector<double>&b){
            return a[2] > b[2];
        });
        
        for(int i = 0; i < n; i++){
                if(capacity >= ans[i][1]){
                capacity = capacity - ans[i][1];
                result += ans[i][0];
            }
            else{
                result += ans[i][2] * capacity;
                break;
            }
        }
        return result;
    }
};
