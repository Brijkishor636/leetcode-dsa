class Solution {
public:
    int  findddpeak(vector<int>&nums,int start,int end,int n){
        int mid=start+(end-start)/2;
        if((mid==0 ||  nums[mid-1]<=nums[mid]) && (mid==n-1 || nums[mid+1]<=nums[mid]))
              return mid;
        else if(mid>0 && nums[mid-1]>nums[mid]){
            return findddpeak(nums,start,mid-1,n);
        }
        else{
            return findddpeak(nums,mid+1,n-1,n);
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
       return  findddpeak(nums,start,end,n);
    }
};