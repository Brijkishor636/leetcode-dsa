
class Solution {
  public:
    long sum_of_ap(long n, long a, long d) {
        int sum = 0;
        sum = (n * (2 * a + (n - 1) * d)) / 2;
        return sum;
    }
};