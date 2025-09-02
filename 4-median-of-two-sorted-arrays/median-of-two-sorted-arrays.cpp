class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
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

        int size = nums1.size();
        if (size % 2 == 1) {
            return nums1[size / 2];
        } else {
            return (nums1[size / 2 - 1] + nums1[size / 2]) / 2.0;
        }
        
    }
};