class Solution {
  public:
    
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int s = *max_element(arr.begin(), arr.end());
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum = sum + arr[i];
        }
        int e = sum;
        int result = -1;
        while(s <= e){
        int mid = s + (e-s)/2;
        int count = 0;
        long long prefix = 0;
        for(int i = 0; i < n; i++){
            prefix = prefix + arr[i];
            if(prefix == mid){
                count++;
                prefix = 0;
            }
            else if(prefix > mid){
                count++;
                prefix = arr[i];
            }
        }
        if(prefix > 0){
            count++;
        }
        if(count <= k){
            result = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return result;
    }
};