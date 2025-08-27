class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k){
            k = k % n;
        }
        int d = n-k;
        vector<int>arr(n, 0);
        for(int i = 0; i < n; i++){
            arr[i] = nums[(i+d)%n];
        }
        nums = arr;
    }
};