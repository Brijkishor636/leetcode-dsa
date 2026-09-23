class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<pair<int, pair<int, int>>>arr;
        for(int i = 0; i < s.size(); i++){
            arr.push_back({i+1, {s[i], f[i]}});
        }
        sort(arr.begin(), arr.end(), [](const pair<int, pair<int, int>>&a, const pair<int, pair<int, int>>&b){
            return (a.second.second < b.second.second);
        });
        
        vector<int>result;
        if (arr.empty()) return result;
        result.push_back(arr[0].first);
        int last = arr[0].second.second;
        for(int i = 1; i < s.size(); i++){
            if(arr[i].second.first > last){
                result.push_back(arr[i].first);
                last = arr[i].second.second;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};