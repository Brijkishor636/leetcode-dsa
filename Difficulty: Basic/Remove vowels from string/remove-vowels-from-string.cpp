// User function template for C++
class Solution {
  public:

    string removeVowels(string& s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                s.erase(i, 1);
                i--;
            }
        }
        return s;
    }
};