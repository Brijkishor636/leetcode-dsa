class Solution {
  public:
    int largestPrimeFactor(int n) {
        int largest = -1;
        for(int i = 2; i*i <= n; i++){
            while(n % i == 0){
                largest = i;
                n = n / i;
            }
        }
        if(n > 1)
            largest = n;
        return largest;
    }
};