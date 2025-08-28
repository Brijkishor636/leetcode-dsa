class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int>result(2,0);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n-1; i++){
            if(arr[i] == arr[i+1]){
                result[0] = arr[i];
            }
        }
         int expected = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == expected) {
                expected++;
            } 
            else if (arr[i] > expected) {
                result[1] = expected;
                break;
            }
        }
        if (result[1] == 0) {
            result[1] = n;
        }
        return result;
    }
};