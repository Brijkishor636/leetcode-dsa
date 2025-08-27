class Solution {
public:
    int left_most(vector<int>&nums, int target){
        int idx = -1;
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                idx = mid;
                e = mid - 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return idx;
    }

    int right_most(vector<int>&nums, int target){
        int idx = -1;
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                idx = mid;
                s = mid + 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = left_most(nums, target);
        int last = right_most(nums, target);
        return {first, last};
    }
};