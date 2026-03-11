// User function template for c++
class Solution {
  public:
    string removeChars(string str1, string str2) {
        // for(int i = 0; i < str2.size(); i++){
        //     for(int j = 0; j < str1.size(); j++){
        //         if(str2[i] == str1[j])
        //             str1.erase(j, 1);
        //             j--;
        //     }
        // }
        // return str1;
        
        
        // unordered_set<char>s(str2.begin(), str2.end());
        // string ans = "";
        // for(auto it: str1){
        //     if(s.find(it) == s.end()){
        //         ans += it;
        //     }
        // }
        // return ans;
        
        
        vector<int>mark(256, 0);
        for(auto c: str2){
            mark[c] = 1;
        }
        string ans = "";
        for(auto it: str1){
            if(mark[it] == 0)
                ans += it;
        }
        return ans;
    }
};
