class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // set<int>s;
        // int n = arr.size();
        // vector<int>temp;
        // for(int i = 0; i <= n-k; i++){
        //     for(int j = i; j < i+k; j++){
        //         s.insert(arr[j]);
        //     }
        //     temp.push_back(s.size());
        //     s.clear();
        // }
        // return temp;
        
        unordered_map<int, int>mp;
        vector<int>temp;
        for(int i = 0; i < k; i++){
            mp[arr[i]]++;
        }
        temp.push_back(mp.size());
        for(int i = k; i < arr.size(); i++){
            mp[arr[i-k]]--;
            mp[arr[i]]++;
            if(mp[arr[i-k]] == 0){
                mp.erase(arr[i-k]);
            }
            temp.push_back(mp.size());
        }
        return temp;
    }
};