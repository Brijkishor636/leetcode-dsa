// User function Template for C++

class Solution {
  public:
    string preToInfix(string str) {
        reverse(str.begin(), str.end());
        stack<string>st;
        int i = 0;
        while(i < str.size()){
            if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')){
                st.push(string(1, str[i]));
            }
            else{
                string result = "";
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                result += "(" + top1 + str[i] + top2 + ")";
                st.push(result);
            }
            i++;
        }
        return st.top();
    }
};