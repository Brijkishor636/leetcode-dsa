class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s = strs[0];
        string e = strs.back();
        int i = 0;
        while(i < s.size() && i < e.size()){
            if(s[i] == e[i]){
                i++;
            }
            else
                break;
        }
        return s.substr(0, i);
    }
};