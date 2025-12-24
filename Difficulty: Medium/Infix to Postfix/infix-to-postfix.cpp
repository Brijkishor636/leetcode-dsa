class Solution {
  public:
    int priority(char c){
        if(c == '+' || c == '-'){
            return 1;
        }
        else if(c == '*' || c == '/'){
            return 2;
        }
        else if(c == '^'){
            return 3;
        }
        else 
            return -1;
    }
    string infixToPostfix(string& s) {
        string result;
        int i = 0;
        stack<char>st;
        while(i < s.size()){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                result = result + s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    result = result + st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while (!st.empty() &&
                    (priority(s[i]) < priority(st.top()) ||
                    (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
                    result = result + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
                result = result + st.top();
                st.pop();
            }
        return result;
    }
};
