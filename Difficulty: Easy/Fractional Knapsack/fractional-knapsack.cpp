class Solution {
  public:
    static bool comp(const pair<int, int>&p1, const pair<int, int>&p2){
        return (double)p1.first/p1.second > (double)p2.first/p2.second; 
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int, int>>arr;
        for(int i = 0; i < val.size(); i++){
            arr.push_back({val[i], wt[i]});
        }
        sort(arr.begin(), arr.end(), comp);
        
        int i = 0;
        double sum = 0;
        while (i < n && capacity > 0) {
            if (arr[i].second <= capacity) {
                sum += arr[i].first;
                capacity -= arr[i].second;
            }
            else {
                sum += (double)arr[i].first / arr[i].second * capacity;
                capacity = 0;
            }
            i++;
        }
        return sum;
    }
};
