class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int>arr = nums1;
        int n = nums1.size();
        int m = nums2.size();
        nums1.clear();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(arr[i] <= nums2[j]){
                nums1.push_back(arr[i]);
                i++;
            }
            else{
                nums1.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n){
            nums1.push_back(arr[i]);
            i++;
        }
        while(j < m){
            nums1.push_back(nums2[j]);
            j++;
        }
        return nums1[k-1];
    }
};