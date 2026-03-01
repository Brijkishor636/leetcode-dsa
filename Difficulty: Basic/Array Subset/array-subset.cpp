class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int>mp;
        for(int i = 0; i < a.size(); i++){
            mp[a[i]]++;
        }
        for(int j = 0; j < b.size(); j++){
            if(mp[b[j]] == 0)
                return false;
            mp[b[j]]--;
        }
        return true;
    }
};