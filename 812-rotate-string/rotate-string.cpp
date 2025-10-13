class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        int n = goal.size();
        for(int i = 0; i < n; i++){
            string sorted = (goal.substr(i))+(goal.substr(0, i));
            if(s == sorted){
                return true;
            }
        }
        return false;
    }
};