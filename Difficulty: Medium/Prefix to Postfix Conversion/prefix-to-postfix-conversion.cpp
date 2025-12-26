// User function Template for C++

class Solution {
  public:
    string preToPost(string str) {
        reverse(str.begin(), str.end());
        int i = 0;
        stack<string>st;
        while(i < str.size()){
            if(isalnum(str[i])){
                st.push(string(1, str[i]));
            }
            else{
                string result = "";
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                result += top1 + top2 + str[i];
                st.push(result);
            }
            i++;
        }
        return st.top();
    }
};