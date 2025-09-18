class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
        }
        int avg = sum/n;
        int count = avg+1;
        if(avg <= 0){
            count = 1;
        }
        for(int i = 0; i < n; i++){
            if(count == nums[i]){
                count++;
                i = -1;
            }
        }
        return count;
    }
};