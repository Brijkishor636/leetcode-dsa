class Solution {
public:
    int pivotElement(vector<int>&nums){
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }

    int findMin(vector<int>& nums) {
        int k = pivotElement(nums);
        return nums[k];
    }
};