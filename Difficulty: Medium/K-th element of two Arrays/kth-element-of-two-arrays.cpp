class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
  int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return kthElement(nums2, nums1, k);
        int s = max(0, k - n2);
        int e = min(k, n1);
        while(s <= e){
            int mid1 = s + (e-s)/2;
            int mid2 = k - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1-1 >= 0) l1=nums1[mid1-1];
            if(mid2-1 >= 0) l2=nums2[mid2-1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            }
            else if(l1 > r2){
                e = mid1 - 1;
            }
            else{
                s = mid1 + 1;
            }
        }
        return -1;
    }
};