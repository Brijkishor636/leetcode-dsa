#include<algorithm>

class Solution {
public:
    char findTheDifference(string s, string t) {
        
    int n1 = s.length();
    int n2 = t.length();

    char temp;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(int i = 0; i < n2-1; i++){
        if (s[i] != t[i])
        {
            temp = t[i];
            return temp;
        } 
    }

    return t[n2-1];
}
    
};