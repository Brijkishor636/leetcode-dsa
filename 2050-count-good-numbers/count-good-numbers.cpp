class Solution {
public:
    int M = 1e9+7;
    long long power(long a, long b){
        if(b == 0){
            return 1;
        }
        long long half = power(a, b/2)%M;
        long long ans = (half * half) % M;
        if(b % 2 == 1){
            ans = (a * ans) % M;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long result = (power(5, (n+1)/2) * power(4, n/2)) % M;
        return result;
    }
};