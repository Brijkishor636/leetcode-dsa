class Solution {
public:
    int maxDepth(string s) { 
        stack<char>st;
        int maxi = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push('(');
                count++;
                maxi = max(maxi, count);
            }
            else if(s[i] == ')'){
                st.pop();
                count--;
            }
        }
        return maxi;
    }
};