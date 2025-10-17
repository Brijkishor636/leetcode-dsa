class Solution {
  public:
    void generateBinstr(vector<string>&ans, string str, int n){
        if(str.size() == n){
            ans.push_back(str);
            return;
        }
        
        generateBinstr(ans, str+"0", n);
        generateBinstr(ans, str+"1", n);
    }
    vector<string> binstr(int n) {
        vector<string>ans;
        generateBinstr(ans, "", n);
        return ans;
    }
};