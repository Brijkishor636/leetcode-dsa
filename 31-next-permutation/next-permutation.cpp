class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i >= 1 && nums[i] <= nums[i-1]){
            i--;
        }
        if(i > 0){
            int j = nums.size()-1;
            while(nums[j] <= nums[i-1])
                j--;
            swap(nums[j], nums[i-1]);
        }
        reverse(nums.begin()+i, nums.end());
    }
};