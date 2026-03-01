// User function template for C++
class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        int right = 0;
        int left = 0;
        for(int i = 0; i < arr.size(); i++){
            right += arr[i];
        }
        for(int i = 0; i < arr.size(); i++){
            right = right - arr[i];
            if(left == right){
                return "true";
            }
            left = left + arr[i];
        }
        return "false";
    }
};