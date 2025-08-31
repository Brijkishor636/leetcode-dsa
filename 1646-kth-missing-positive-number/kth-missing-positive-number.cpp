class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 1;
        vector<int>nums;
        int i = 0;
        while(i < arr.size()){
            if(arr[i] != count){
                nums.push_back(count);
            }
            else{
                i++;
            }
            count++;
        }
        if(nums.size() < k){
            for(int i = nums.size(); i < k; i++){
                nums.push_back(count);
                count++;
            }
        }
        return nums[k-1];
    }
};