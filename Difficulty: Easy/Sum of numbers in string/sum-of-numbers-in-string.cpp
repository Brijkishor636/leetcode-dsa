class Solution {
  public:
    int findSum(string& s) {
        int i = 0;
        int sum = 0;
        string number = "";
        while(i < s.size()){
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                number += s[i];
            }
            else{
                if(!number.empty()){
                    sum = sum + stoi(number);
                    number = "";
                }
            }
            i++;
        }
        if(!number.empty()){
            sum = sum + stoi(number);
        }
        return sum;
    }
};