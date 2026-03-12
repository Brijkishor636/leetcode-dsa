class Solution {
  public:
    string toHexadecimal(int n){
        string res = "";
        unordered_map<int, char>mp;
        mp[10] = 'a';
        mp[11] = 'b';
        mp[12] = 'c';
        mp[13] = 'd';
        mp[14] = 'e';
        mp[15] = 'f';
        while(n > 0){
            int digit = n % 16;
            if(digit < 10)
                res = res + to_string(digit);
            else{
                res = res + mp[digit];
            }
            n = n / 16;
        }
        return res;
    }
    string encryptString(string s) {
        char ch = s[0];
        int count = 1;
        string temp = "";
        string ans = "";
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ch){
                count++;
            }
            else{
                ans += ch;
                temp = toHexadecimal(count);
                ans += temp;
                ch = s[i];
                count = 1;
            }
        }
        ans += ch;
        temp = toHexadecimal(count);
        ans += temp;
        string res = "";
        for(int i = ans.size()-1; i >= 0; i--){
            res.push_back(ans[i]);
        }
        return res;
    }
};