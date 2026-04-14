class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0;
        int count = 0; 
        int maxi = 0;
        
        while(i < arr.size() && j < dep.size()){
            if(arr[i] <= dep[j]){
                count++;
                maxi = max(count, maxi);
                i++;
            }
            else{
                count--;
                j++;
            }
        }
        return maxi;
    }
};
