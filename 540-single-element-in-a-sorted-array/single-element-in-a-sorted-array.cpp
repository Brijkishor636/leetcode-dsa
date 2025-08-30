class Solution {
public:
    int nonDuplicate(vector<int>&nums, int s, int e){
        if(s == e){
            return nums[s];
        }
        int mid = s + (e-s)/2;
        if(mid % 2 == 1){
            mid--;
        }
        if(nums[mid+1] == nums[mid]){
            return nonDuplicate(nums, mid+2, e);
        }
        else
            return nonDuplicate(nums, s, mid);
    }
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        return nonDuplicate(nums, s, e);
    }
};