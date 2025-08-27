class Solution {
public:
    bool find_element(vector<int>&nums, int target, int s, int e){
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int k = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                k++;
                break;
            }
            else{
                k++;
            }
        }

        int result = find_element(nums, target, 0, k-1);
        if(result == 0){
            result = find_element(nums, target, k, nums.size()-1);
        }
        return result;
    }
};