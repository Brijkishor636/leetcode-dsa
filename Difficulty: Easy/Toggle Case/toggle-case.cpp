class Solution {
  public:
    string toggleCase(string &s) {
        // for(int i = 0; i < s.size(); i++){
        //     if(s[i] >= 'a' && s[i] <= 'z')
        //         s[i] = s[i] - ('a' - 'A');
        //     else
        //         s[i] = s[i] + ('a' - 'A');
        // }
        // return s;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 32;
            else
                s[i] = s[i] + 32;
        }
        return s;
    }
};