class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto maxi = max_element(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int add = *maxi - nums[i];
            count += add;
        }
        return count;
    }
};