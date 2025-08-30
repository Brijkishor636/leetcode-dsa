class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sum = 0;
        int result = 0;
        int maxi = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
            maxi = max(maxi, nums[i]);
        }
        int s = sum / threshold;
        int e = maxi;
        if(!s){
            s = 1;
        }
        while(s <= e){
            int mid = s + (e-s)/2;
            int div = 0;
            for(int i = 0; i < n; i++){
                div = div + nums[i]/mid;
                if(nums[i]%mid){
                    div++;
                }
            }
            if(div > threshold){
                s = mid + 1;
            }
            else{
                result = mid;
                e = mid - 1;
            }
        }
        return result;
    }
};