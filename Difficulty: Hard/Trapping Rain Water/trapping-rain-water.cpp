class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int i = 0; 
        int j = arr.size()-1;
        int right = 0;
        int left = 0;
        int water = 0;
        while(i < j){
            if(arr[i] > arr[j]){
                right = max(right, arr[j]);
                water += right - arr[j];
                j--;
            }
            else{
                left = max(left, arr[i]);
                water += left - arr[i];
                i++;
            }
        }
        return water;
    }
};