// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        int i = 0;
        stack<string>st;
        while(i < exp.size()){
            if(isalnum(exp[i])){
                st.push(string(1, exp[i]));
            }
            else{
                string result = "";
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                result += "(" + top2 + exp[i] + top1 + ")";
                st.push(result);
            }
            i++;
        }
        return st.top();
    }
};