class Solution {
public:
    string removeOuterParentheses(string s) {
        int openCount = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(openCount > 0){
                    ans += s[i];
                }
                openCount++;
            }
            else{
                openCount--;
                if(openCount > 0){
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};