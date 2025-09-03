class Solution {
public:
    int possible(vector<int>&nums, int mid){
        int prefix = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix = prefix + nums[i];
            if(prefix == mid){
                count++;
                prefix = 0;
            }
            else if(prefix > mid){
                count++;
                prefix = nums[i];
            }
        }
        if(prefix > 0)
            count++;
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
        }
        int s = *max_element(nums.begin(), nums.end());
        int e = sum;
        int result = 0;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(possible(nums, mid) <= k){
                result = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return result;
    }
};