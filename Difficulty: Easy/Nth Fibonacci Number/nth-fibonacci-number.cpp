class Solution {
  public:
    int nthFibonacci(int n) {
        // memoization
        vector<int>arr(n+1, -1);
        if(n <= 1){
            return n;
        }
        if(arr[n] != -1){
            return arr[n];
        }
        else{
            return arr[n] = nthFibonacci(n-1) + nthFibonacci(n-2);
        }
    }
};