class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxi = 0;
        int count = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1])
                continue;
            if(nums[i]+1 == nums[i+1]){
                count++;
            }
            else{
                maxi = max(maxi, count);
                count = 1;
            }
        }
        maxi = max(maxi, count);
        // set<int>s(nums.begin(), nums.end());
        // auto it = s.begin();
        // auto prev = it;
        // it++;
        // for(; it != s.end(); it++){
        //     if(*prev+1 == *it){
        //         count++;
        //     }
        //     else{
        //         maxi = max(maxi, count);
        //         count = 1;
        //     }
        //     prev = it;
        // }
        // maxi = max(count, maxi);
        return maxi;
    }
};