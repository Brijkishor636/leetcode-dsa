class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k = k % n;
        int m = nums.size() - k;
        reverse(nums.begin(), nums.begin()+m);
        reverse(nums.begin()+m, nums.end());
        return reverse(nums.begin(), nums.end());

    }
};