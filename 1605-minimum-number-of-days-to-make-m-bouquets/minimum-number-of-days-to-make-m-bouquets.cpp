class Solution {
public:
    int possible(vector<int>&arr, int k, int mid){
        int count = 0;
        int localcount = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= mid){
                count++;
                if(count == k){
                    localcount++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return localcount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 1;
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            int check = possible(bloomDay, k, mid);
            if(check >= m){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
            return ans;
    }
};