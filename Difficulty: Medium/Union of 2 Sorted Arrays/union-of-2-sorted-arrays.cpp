class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int>s;
        int i = 0; 
        int j = 0; 
        while(i < a.size()){
            s.insert(a[i]);
            i++;
        }
        while(j < b.size()){
            s.insert(b[j]);
            j++;
        }
        vector<int>result;
        for(auto x: s){
            result.push_back(x);
        }
        return result;
    }
};
