class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int sign = 1;
        int i = 0; 
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if(i < s.size() && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1:1;
            i++;
        }
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            result = result * 10 + s[i]-'0';

            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
            i++;
        }
        return result*sign;
    }
};