class Solution {
public:
    int addNum(int n, int &sum){
        while(n > 0){
            int digit = n % 10;
            sum = sum + digit;
            n = n / 10;
        }
        return sum;
    }
    int addDigits(int num) {
        int sum = 0;
        if(num < 10){
            return num;
        }
        while(num / 10 != 0){
            sum = 0;
            addNum(num, sum);
            num = sum;
        }
        return sum;
    }
};