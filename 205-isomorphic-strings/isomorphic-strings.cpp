class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, char>s1;
        unordered_map<char, char>s2;
        for(int i = 0; i < s.size(); i++){
            char a = s[i];
            char b = t[i];
            if(s1.count(a) && s1[a] != b){
                return false;
            }
            if(s2.count(b) && s2[b] != a){
                return false;
            }
            s1[a] = b;
            s2[b] = a;
        }
        return true;
    }
};