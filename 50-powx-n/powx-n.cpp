class Solution {
public:
    double fastPow(double x, long long n) {
        if (n == 0) return 1;
        double half = fastPow(x, n / 2);
        double ans = half * half;
        if (n % 2 == 1) {
            ans = x * ans;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};
