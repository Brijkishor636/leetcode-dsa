// User function template for C++

class Solution {
  public:
    string removeSpecialCharacter(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                ans += s[i];
            }
        }
        if(ans == ""){
            return "-1";
        }
        return ans;
    }
};