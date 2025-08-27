class Solution {
public:
    int search(vector<int>&nums, int target, int s, int e){
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return -1;
    }

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

    int search(vector<int>& nums, int target) {
        int k = pivotElement(nums);
        int idx = search(nums, target, 0, k-1);
        if(idx == -1){
            idx = search(nums, target, k, nums.size()-1);
        }
        return idx;
    }
};