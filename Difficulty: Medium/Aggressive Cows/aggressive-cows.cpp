class Solution {
  public:
    bool possible(vector<int>&stalls, int mid, int k){
        int c = 1;
        int position = stalls[0];
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i]-position >= mid){
                c++;
                position = stalls[i];
            }
            if(c == k){
                return true;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int s = 1;
        int maxi = *max_element(stalls.begin(), stalls.end());
        int e = maxi - stalls[0];
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(possible(stalls, mid, k)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return ans;
    }
};