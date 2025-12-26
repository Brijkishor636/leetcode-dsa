class Solution {
  public:
    string reverseString(string &s){
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                s[i] = ')';
            }
            else if(s[i] == ')'){
                s[i] = '(';
            }
        }
        return s;
    }
    
    int priority(char ch){
        if(ch == '+' || ch == '-'){
            return 1;
        }
        else if(ch == '*' || ch == '/'){
            return 2;
        }
        else if(ch == '^'){
            return 3;
        }
        return -1;
    }
    
    string infixToPrefix(string &s) {
        string str = reverseString(s);
        stack<char>st;
        string result = "";
        int i = 0;
        while(i < str.size()){
            if(isalnum(str[i])){
                result += str[i];
            }
            else if(str[i] == '('){
                st.push(str[i]);
            }
            else if(str[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while((!st.empty()) && ((priority(st.top()) > priority(str[i])) || (priority(st.top()) == priority(str[i]) && str[i] == '^'))){
                    result += st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
            i++;
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
