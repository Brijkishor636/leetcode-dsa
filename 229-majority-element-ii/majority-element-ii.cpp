class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        vector<int>res;
        int k = nums.size() / 3;
        for(auto x: mp){
            if(x.second > k){
                res.push_back(x.first);
            }
        }
        return res;
    }
};