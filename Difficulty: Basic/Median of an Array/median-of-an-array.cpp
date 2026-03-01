class Solution {
  public:
    double findMedian(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double result = 0;
        if(n % 2 == 0){
            result = (arr[n/2] + arr[n/2 - 1]) / 2.0;
        }
        else{
            result = arr[n/2];
        }
        return result;
    }
};