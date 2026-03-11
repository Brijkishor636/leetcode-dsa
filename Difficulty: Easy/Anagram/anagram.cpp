class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.size() != s2.size())
            return false;
        string newStr1 = s1;
        sort(newStr1.begin(), newStr1.end());
        string newStr2 = s2;
        sort(newStr2.begin(), newStr2.end());
        if(newStr1 != newStr2)
            return false;
        return true;
    }
};