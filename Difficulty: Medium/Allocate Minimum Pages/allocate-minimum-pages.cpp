class Solution {
  public:
    int findPages(vector<int>& arr, int m) {
        int n = arr.size();
    if(n < m){
        return -1;
    }
    long long sum = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
        maxi = max(maxi, arr[i]);
    }
    int s = maxi;
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
        if(count <= m){
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