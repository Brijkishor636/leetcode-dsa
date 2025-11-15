class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int>prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int> mp;
        for(int j = 0; j < n; j++){
            int temp = prefix[j] - k;
            if(prefix[j] == k){
                count++;
            }
            if(mp.find(temp) != mp.end()){
                count += mp[temp];
            }
            mp[prefix[j]]++;
        }
        return count;
    }
};