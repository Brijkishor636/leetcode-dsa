class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int count = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++){
        //         sum += nums[j];
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        unordered_map<int, int>mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum - k;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};