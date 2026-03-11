

class Solution {
  public:
    string encryptString(string s) {
        char ch = s[0];
        int count = 1;
        string ans = "";
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ch){
                count++;
            }
            else{
                ans += ch;
                ans += to_string(count);
                ch = s[i];
                count = 1;
            }
        }
        ans += ch;
        ans += to_string(count);
        string res = "";
        for(int i = ans.size()-1; i >= 0; i--){
            res.push_back(ans[i]);
        }
        return res;
    }
};