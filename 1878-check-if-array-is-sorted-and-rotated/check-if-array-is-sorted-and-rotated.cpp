class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(is_sorted(nums.begin(), nums.end()))
            return true;
        vector<int>arr;
        for (int i = 0; i < n; i++)
        {
            if(nums[i+1] < nums[i]){
                arr.push_back(nums[i]);
                break;
            }
            else{
                arr.push_back(nums[i]);
            }
        }
        vector<int>result(n, 0);
        int k = arr.size();
        for(int i = 0; i < n; i++){
            result[i] = nums[(i+k)%n];
        }

        if(is_sorted(result.begin(), result.end()))
            return true;
        else
            return false;
    }
};